//******************************
//???:4.cpp
//??: ??? 1300012754
//??:2013.10.25
//??:??????
//******************************

int main()
{
	int a[10010];  //????
	int m;  //?????
	int t = 1;  //????m????????????
	int flag = 1; //????
	int b, c; //m??????
	memset(a, 0, sizeof(a)); //?????
	
	a[1] = 2;  //?????????2
	cin >> m;  //???????

	//?????????
	for (int i = 3; i <= m; i++)  //?3????
	{
		//?i????i?????????t???
		for (int j = 1; j <= t; j++)
		{
			flag = 1;  //????????????1???0
			if (i % a[j] == 0) //??????????
			{
				flag = 0;      //?????0
				break;         //exit for
			}
		}
		if (flag == 1)
		{
			a[t+1] = i;  //????t??????????????
			t = t + 1;   //?????????1
		}
	}

	//??????????????????????????2????????????a[2] = 3???
	for (int j = 2; j <= t; j++)
	{
		b = a[j];     //???????
		c = m - a[j]; //????????????????????
		if (b > c)    //????????????????????????????????
			break;

		//??c??????????????
		for (int i = t; i >= 2; i--)
		{
			if (c == a[i])
			{
				cout << b << " " << c << endl; //????????????
				break;
			}
		}
	}
	return 0;
}

