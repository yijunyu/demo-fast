int main()                      //???
{
	int n,i=0,a[100];           //????n,i???a[100]
	cin>>n;                     //??n
	while(i<n)                  //???????i<n?????????
	{
		cin>>a[i];              //??????a[i]
		i++;}                   //?????i??1
	for(;i>1;i--)               //????????????????i>1????????i??1
	{
		cout<<a[i-1]<<" ";        //?????????????
	}
	cout<<a[0]<<endl;            //????????????
	return 0;                   //??????
}