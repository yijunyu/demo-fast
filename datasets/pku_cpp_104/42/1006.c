//**********************************
//*  ????????              *
//*  ??????                  *
//*  ?????2011?10?23?      *
//**********************************
int main()
{
	int n , a[100001] , x , k , sum;
	int i , j;
	cin >> n;//n??????????
	sum = 0;//sum??????????,??????0
	for(i = 1;i <= n;i ++)
	{
		cin >> x;
		a[i] = x;
	}//????????????
	cin >> k;//??????????
	for(i = 1;i <= n - sum;i ++)
	{
		if(a[i] == k)//???????????????
		{
			for(j = i + 1;j <= n - sum;j ++)
				a[j - 1] = a[j];//????????????
			sum = sum + 1;//?????????1
			i --;//?????1,????????????
		}
	}
	for(i = 1;i <= n - sum;i ++)
	{
		if(i < n - sum)
			cout << a[i] << " ";//???n-sum?????
		else
			cout << a[i] << endl;//??????
	}
	return 0;
}