//??????   ???   1000012729
int main()
{
	int a,b,c,i;                                      //??a,b,c?A,B,C??????
	char eat[3];                                      //?????????????
	int ansa=0,ansb=0,ansc=0;                         //????????
	for(a=0;a<3;a++)
	{
		for(b=0;b<3;b++)
		{
			for(c=0;c<3;c++)
			{
				ansa=(b<a)+(c==a);                    //A??
				ansb=(a<b)+(a<c);                     //B??
				ansc=(c<b)+(b<a);                     //C??
				if(ansa==a && ansb==b && ansc==c)     //????????????????????
				{
					eat[a]='A';                       //???????????????
					eat[b]='B';
					eat[c]='C';
				}
			}
		}
	}
	for(i=2;i>=0;i--)                                  //??????????????
		cout<<eat[i];                            //???????????????????????????????
		cout<<endl;
		return 0;
}
