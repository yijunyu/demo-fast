/*
					? ? ??1000012827_1.cpp
					?    ?????
					?????20101117
					??????????????
**/
int main()
{
	char minuend[101], subtrahend[101];											//????????
	int n, k = 1, c = -1;														//??????n????????c??????????????????
	cin >> n;
	for(k = 1; k <= n; k ++)
	{
		cin.get();																//????
		//????????????????????????a b ????????result????d e????
		int m[100] = {0}, s[100] = {0}, a, b, result[100] = {0}, d = 99, e = 99;
		cin.getline(minuend, 100);												//??????
		cin.getline(subtrahend, 100);
		a = strlen(minuend);													//???????????
		b = strlen(subtrahend);
		for(int i = a - 1; i >= 0; i --)										//???????
		{
			m[d] = minuend[i] - '0';
			d --;
		}
		for(int i = b - 1; i >= 0; i --)
		{
			s[e] = subtrahend[i] - '0';
			e --;
		}
		for(int i = 99; i > 99 - a; i --)										//????????
		{
			if(m[i] >= s[i])
				result[i] = m[i] - s[i];
			else																//????????????????????
			{
				m[i] = m[i] + 10;
				m[i - 1] --;
				result[i] =m[i] - s[i];
			}
		}
		for(int i = 0; i < 100; i ++)
			if(result[i] != 0)													//???????????????
			{
				c = i;
				break;
			}
			if(c == -1)															//?????????
				cout << "0" << endl;
			else																//????????????????????99?
			{
				for(int i = c; i < 99; i ++)
					cout << result[i];
				cout << result[99] << endl;										//?????100?????
			}
	}
		return 0;
	}