int main ()
{
	int a , p ; // ??a???????? p?3 5 7????? p ?????
	cin >> a ; // ????a
    p = 0 ; // ???p?0
	if (a % 3 == 0 ) 
	{
		cout << "3" ;
		p = p + 1 ;
	} // ?? p ?????? ???? �3� ???????? ?????????? p?? 
	if (a % 5 == 0 )
	{
		if (p > 0)
		{
			cout << " 5" ;
		}
		else 
		{
			cout << "5" ;
		} // ???????????????a ?? �5�???????? ???????
		p = p + 1 ; // p??
	}
	if (a % 7 == 0 )
	{
		if (p > 0)
		{
			cout << " 7" ;
		}
		else 
		{
			cout << "7" ;
		}
		p = p + 1 ;
	} // ???????????????? a ???? � 7� ????�7� ?????
	if (p == 0) 
	{
		cout << "n" ;
	} // ??????????a ???? "n" 
	cout << endl ; // ????
	return 0 ;
}
		
