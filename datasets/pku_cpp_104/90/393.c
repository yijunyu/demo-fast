//
//	????:	?????
//	????:	?M????????N???????????????????????????????
//	????:	?  ? ( ? ?: 1000012733 )
//	????:	2010 ? 12 ? 06 ?
//
int maxapple ( int, int );										/*????????????maxapple?????????????????????????
																????????????????????????????????????*/
int main()
{
	int t, i, m, n, k;											/*??????????????t??????????i????????m?n??????
																??????????k??????????????*/
	cin >> t;													//???????????
	for ( i = 1; i <= t; i ++ )
	{
		cin >> m >> n;											//???i??????m????????n???????
		k = maxapple ( m, n );									//????maxapple????????????????????k
		cout << k << endl;										//??k??????
	}
	return 0;
}
int maxapple ( int m, int n )									//????maxapple?????????????m?n????????????????
{
	int k;														//k??????????????????????
	if ( m == 0 )
		return 1;												//??m?0????????????????????????????
	if ( n == 1 )
		return 1;												//??n?1?????????????????????????????????????
	if ( m >= n )
	{
		k = maxapple ( m - n, n ) + maxapple ( m, n - 1 );
		return k;												/*??m?????n?????????????n??????m - n????????????
																?n - 1?????m???????????*/
	}
	if ( m < n )
	{
		k = maxapple ( m, n - 1 );
		return k;												//??m??n?????????????n - 1?????m???????????
	}
}