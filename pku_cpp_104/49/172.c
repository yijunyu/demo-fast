/**
 * ? ? ??????
 * ?    ?????
 * ????: 2010?11?26?
 * ?????????????????????
*/
int main()                                  
{
	int i , j, k, t;
	char a[501];
	cin>>a;
	int len = strlen(a);								
	for( i = 2; i <= len; i++ )							//???????????2???
	{
		for( j = 0; j < len - i + 1; j++ )					//?????????????????????????????-????????
		{
			for( k = j; k <= j + i - 1; k++ )				//??j???j+i-1?i?
			{
				if( a[k] != a[2*j+i-1-k] )		//????i?????????????????????j??i??????????
					break;
			}
			if(k == j + i)							//?????????????i??????????
			{
				for( t = j; t <= j + i - 1; t++)			//??j????????i??????,???????????
					cout<<a[t];
				cout<<endl;
			}
		}
	}                 
    return 0;
}