//********************************
//*????7???????   **
//*?????? 1300012855 **
//*???2013.10.11  **
//********************************


int main(void)
{
	int n, sum = 0; // ??????n?????????n?????sum????????0 
 	cin >> n;
 	for(int i = 1; i <= n; i++) // ??????i?????n?
	{
		
// ?????????7????????????????7?????????????7 
		if( (i%7 != 0) && ((i / 10) != 7) && ((i - (i / 10) * 10) != 7))  
			sum += i * i; // sum???i??? 
	} 
	cout << sum << endl;
	return 0;
} 