/************************/
/*    ???????    */
/*    ??? pyyaoer    */
/*   ??  2011.12.4    */
/************************/
int main()
{
	char c[1000];
	char *p=NULL;                  //?????
	p=c;
	gets(c);
	for (;*p!='\0';p++)            //???????????
	{
		if (*p==' ')               //?????????????
		{
			cout<<" ";
			for (;*p==' ';p++){}   //???????
			p--;
		}
		else cout<<*p;             //??????????
	}
	cout<<endl;
	return 0;
}