int main()
{
	int n,a[100];  //??a?????7????
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i%7==0 || i%10==7 || (i-70>=0 && i-70<10)) //???7???????a????1????0
			a[i]=1;
		else
			a[i]=0;
	}
	int sum=0; //??????0
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
			sum+=i*i;    //??7????????
	}
	cout<<sum<<endl; //????
	return 0;
}
