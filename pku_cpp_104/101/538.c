//****************************************
//*??????                         **
//*????? 1100012762                **
//*???2011.10.21                     **
//****************************************
int main()
{
	int a[4], A[4];
	char ch[4] = {0, 65, 66 ,67}, b[4];                                      //???????????b???????????????
	for (a[1] = 1; a[1] <= 3; a[1]++)
	{
		for (a[2] = 1; a[2] <= 3; a[2]++)
		{
			for (a[3] = 1; a[3] <= 3; a[3]++)
			{
				A[1] = (a[2] > a[1]) + (a[3] == a[1]);
				A[2] = (a[1] > a[2]) + (a[1] > a[3]);
				A[3] = (a[3] > a[2]) + (a[2] > a[1]);
				if (a[1] + A[1] == 3 && a[2] + A[2] == 3 && a[3] + A[3] == 3)//?????????????????????123??????321?
				{
					for (int i = 1;i <= 3; i++)
					{
						b[a[i]] = ch[i];                                     //?????????????????????????????
					}
					cout << b[1] << b[2] << b[3] << endl;
				}
			}
		}
	}
	return 0;
}