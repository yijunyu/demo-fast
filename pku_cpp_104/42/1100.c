//**********************************
//*????????.cpp            *
//*??????                    *
//*???2011-10-19                *
//**********************************


int main()
{
	int a[100000] = {0};         //?????????
	int n;                       //??n???????????????? 
	int count = 0;               //??count??????????????
	int i, j;                    //??i, j?????
	int num;                     //??num??????
	cin >>n;
	//??n??? 
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	//?????? 
	cin >> num;
	//????????I????????????count?1?????????????????I+1????????I???????????????????I=I-1 
	//??????????????????n - count?????? 
	for (i = 0; i < n - count; i++)
	{
		//???????????????????????????????count?1?????????1?? 
		if (num == a[i])
		{ 
			for (j = i; j < n - 1; j++)
				{
					a[j] = a[j + 1];
				}
				count++;
				i = i - 1;
					}
	}
	//????????????n - count?????? 
	for (i = 0; i != n - count; i++)
	{
		cout << a[i];
		//?????????????????????????? 
		if(i != n - count - 1)
			cout << " ";
	}
	return 0;
}
