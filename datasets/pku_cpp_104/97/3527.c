int main()
{
    int n, a[7], b[7],i;
    cin>>n;
    a[1]=(n-n%100)/100;
    b[1]=n%100;
    a[2]=(b[1]-b[1]%50)/50;
    b[2]=b[1]%50;
    a[3]=(b[2]-b[2]%20)/20;
    b[3]=b[2]%20;
    a[4]=(b[3]-b[3]%10)/10;
    b[4]=b[3]%10;
    a[5]=(b[4]-b[4]%5)/5;  
    b[5]=b[4]%5;
    a[6]=b[5];
    for(i=1; i<=6; i++)
      {
        cout<<a[i]<<endl;     
      }
     int c;cin>>c;  
    return 0;
    
    
    
    
    }
