// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using System.Runtime.InteropServices;
using Test.Cryptography;
using Xunit;

namespace System.Security.Cryptography.X509Certificates.Tests
{
    public static class PfxTests
    {
        [Fact]
        public static void TestConstructor()
        {
            byte[] expectedThumbprint = "71cb4e2b02738ad44f8b382c93bd17ba665f9914".HexToByteArray();

            using (var c = new X509Certificate2(TestData.PfxData, TestData.PfxDataPassword))
            {
                string subject = c.Subject;
                Assert.Equal("CN=MyName", subject);
                byte[] thumbPrint = c.GetCertHash();
                Assert.Equal(expectedThumbprint, thumbPrint);
            }
        }

        [Fact]
        public static void EnsurePrivateKeyPreferred()
        {
            using (var cert = new X509Certificate2(TestData.ChainPfxBytes, TestData.ChainPfxPassword))
            {
                // While checking cert.HasPrivateKey first is most matching of the test description, asserting
                // on the certificate's simple name will provide a more diagnosable failure.
                Assert.Equal("test.local", cert.GetNameInfo(X509NameType.SimpleName, false));
                Assert.True(cert.HasPrivateKey, "cert.HasPrivateKey");
            }
        }

        [Fact]
        public static void TestRawData()
        {
            byte[] expectedRawData = (
                "308201e530820152a0030201020210d5b5bc1c458a558845" +
                "bff51cb4dff31c300906052b0e03021d05003011310f300d" +
                "060355040313064d794e616d65301e170d31303034303130" +
                "38303030305a170d3131303430313038303030305a301131" +
                "0f300d060355040313064d794e616d6530819f300d06092a" +
                "864886f70d010101050003818d0030818902818100b11e30" +
                "ea87424a371e30227e933ce6be0e65ff1c189d0d888ec8ff" +
                "13aa7b42b68056128322b21f2b6976609b62b6bc4cf2e55f" +
                "f5ae64e9b68c78a3c2dacc916a1bc7322dd353b32898675c" +
                "fb5b298b176d978b1f12313e3d865bc53465a11cca106870" +
                "a4b5d50a2c410938240e92b64902baea23eb093d9599e9e3" +
                "72e48336730203010001a346304430420603551d01043b30" +
                "39801024859ebf125e76af3f0d7979b4ac7a96a113301131" +
                "0f300d060355040313064d794e616d658210d5b5bc1c458a" +
                "558845bff51cb4dff31c300906052b0e03021d0500038181" +
                "009bf6e2cf830ed485b86d6b9e8dffdcd65efc7ec145cb93" +
                "48923710666791fcfa3ab59d689ffd7234b7872611c5c23e" +
                "5e0714531abadb5de492d2c736e1c929e648a65cc9eb63cd" +
                "84e57b5909dd5ddf5dbbba4a6498b9ca225b6e368b94913b" +
                "fc24de6b2bd9a26b192b957304b89531e902ffc91b54b237" +
                "bb228be8afcda26476").HexToByteArray();

            using (var c = new X509Certificate2(TestData.PfxData, TestData.PfxDataPassword))
            {
                byte[] rawData = c.RawData;
                Assert.Equal(expectedRawData, rawData);
            }
        }

        [Fact]
        public static void TestPrivateKey()
        {
            using (var c = new X509Certificate2(TestData.PfxData, TestData.PfxDataPassword))
            {
                bool hasPrivateKey = c.HasPrivateKey;
                Assert.True(hasPrivateKey);

                using (RSA rsa = c.GetRSAPrivateKey())
                {
                    byte[] hash = new byte[20];
                    byte[] sig = rsa.SignHash(hash, HashAlgorithmName.SHA1, RSASignaturePadding.Pkcs1);
                    Assert.Equal(s_expectedSig, sig);
                }
            }
        }

        [Fact]
        public static void ExportWithPrivateKey()
        {
            using (var cert = new X509Certificate2(TestData.PfxData, TestData.PfxDataPassword, X509KeyStorageFlags.Exportable))
            {
                const string password = "NotVerySecret";

                byte[] pkcs12 = cert.Export(X509ContentType.Pkcs12, password);

                using (var certFromPfx = new X509Certificate2(pkcs12, password))
                {
                    Assert.True(certFromPfx.HasPrivateKey);
                    Assert.Equal(cert, certFromPfx);
                }
            }
        }

        [Fact]
        public static void ReadECDsaPrivateKey_WindowsPfx()
        {
            using (var cert = new X509Certificate2(TestData.ECDsaP256_DigitalSignature_Pfx_Windows, "Test"))
            using (ECDsa ecdsa = cert.GetECDsaPrivateKey())
            {
                Assert.NotNull(ecdsa);

                if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows))
                {
                    AssertEccAlgorithm(ecdsa, "ECDSA_P256");
                }
            }
        }

        [Fact]
        public static void ReadECDsaPrivateKey_OpenSslPfx()
        {
            using (var cert = new X509Certificate2(TestData.ECDsaP256_DigitalSignature_Pfx_OpenSsl, "Test"))
            using (ECDsa ecdsa = cert.GetECDsaPrivateKey())
            {
                Assert.NotNull(ecdsa);

                if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows))
                {
                    // If Windows were to start detecting this case as ECDSA that wouldn't be bad,
                    // but this assert is the only proof that this certificate was made with OpenSSL.
                    //
                    // Windows ECDSA PFX files contain metadata in the private key keybag which identify it
                    // to Windows as ECDSA.  OpenSSL doesn't have anywhere to persist that data when
                    // extracting it to the key PEM file, and so no longer has it when putting the PFX
                    // together.  But, it also wouldn't have had the Windows-specific metadata when the
                    // key was generated on the OpenSSL side in the first place.
                    //
                    // So, again, it's not important that Windows "mis-detects" this as ECDH.  What's
                    // important is that we were able to create an ECDsa object from it.
                    AssertEccAlgorithm(ecdsa, "ECDH_P256");
                }
            }
        }

        // Keep the ECDsaCng-ness contained within this helper method so that it doesn't trigger a
        // FileNotFoundException on Unix.
        private static void AssertEccAlgorithm(ECDsa ecdsa, string algorithmId)
        {
            ECDsaCng cng = ecdsa as ECDsaCng;

            if (cng != null)
            {
                Assert.Equal(algorithmId, cng.Key.Algorithm.Algorithm);
            }
        }

        private static readonly byte[] s_expectedSig =
            ("44b15120b8c7de19b4968d761600ffb8c54e5d0c1bcaba0880a20ab48912c8fdfa81b28134eabf58f3211a0d1eefdaae115e7872d5a67045c3b62a5da4393940e5a496"
          + "413a6d55ea6309d0013e90657c83c6e40aa8fafeee66acbb6661c1419011e1fde6f4fcc328bd7e537e4aa2dbe216d8f1f3aa7e5ec60eb9cfdca7a41d74").HexToByteArray();

        private static X509Certificate2 Rewrap(this X509Certificate2 c)
        {
            X509Certificate2 newC = new X509Certificate2(c.Handle);
            c.Dispose();
            return newC;
        }
    }
}
