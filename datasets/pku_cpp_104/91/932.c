//*****************************************************************
//*???????????? ***************************************
//*??????? 1200012979 **************************************
//*???2012.12.4 ************************************************
//*****************************************************************
int main()
{
	char a[101], *p = a+1, *q = a;
    cin.getline(a, 101);               //??????p???????
    do                                 //????p--??
	{
		p--;
        cout << (char) (*p + *++p);    //??????
	}
	while(*++p != '\0');
	cout << (char)(*--p + *q) << endl; //????????????
	return 0;
}