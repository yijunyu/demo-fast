/*3?????????????? 
A??B??????C??????? 
B??A??????A??C??? 
C????B????B?A???? 
????????????????????? 
???????????3??????*/
//Goofy 2010 11 19
int main()
{
	char peo[4];
	int a, b, c, i, judger=0;
	peo[3]='\0';
	for (a=0; a<3; a++)
	for (b=0; b<3; b++)
	for (c=0; c<3; c++)
	{
		judger=0;
		peo[a]='A';
		peo[b]='B';
		peo[c]='C';
		if ( (b>a) + (c==a) == 2-a)//A
			judger++;
		if ( (a>b) + (a>c) == 2-b)//B
			judger++;
		if ( (c>b) + (b>a) == 2-c)//C
			judger++;
		if (judger == 3)
			cout<<peo<<endl;
	}
	return 0;
}