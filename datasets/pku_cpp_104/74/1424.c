/*?? - ??????	
??	??-From Whf
??
??????? m ?n ??????????????????m ? n?????m ???n??????????????????????????? no (??????????????????123321?121)?
????
m ? n ?1??????1??????
????
?????????????????????????? no
????
100  200
????
101,131,151,181,191
*/
int huiwen(int x)
{
	int y=0;
	for(;x!=0;)
	{
		y=y*10+x%10;
		x=x/10;
	}
	return y;
}
int zhishu(int x)
{
	int i,k;
	k=x/2;
	for(i=2;x%i!=0&&i<k+1;i++);
	if(i==k+1) return 1;
	else return 0;
}
void main()
{
	int l=1,n,m,i;
	scanf("%d%d",&n,&m);
	for(i=n;i<=m;i++)
	{
		if(i==huiwen(i))
			if(zhishu(i))
			{
				if(l==1){printf("%d",i);l++;}
				else printf(",%d",i);
			}
	}
	if(l==1)
		printf("no");
}
