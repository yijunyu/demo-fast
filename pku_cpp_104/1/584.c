//????????
int kind(int num,int min);              //????kind???num???????min?????????
int main()                              //?????
{
	int n;
	int i;
	int num;
	cin>>n;
	for(i=1;i<=n;i++)
	{
	  cin>>num;                        //??????n????????????????????
	  cout<<kind(num,2)<<endl;
	}
return 0;
}                                     //?????
int kind(int num,int min)             //kind????
{
	if(num<min)                      //??num??min??????????min?????????0
	{return 0;}

	int k=1;                         //????????num=num??????????
	int i;
	for(i=min;i<=num;i++)
	{
		if(num%i==0)                  //??????
	   {
		  k=k+kind(num/i,i);          //?k????num?????i???????????????????????????????min?
	   }

    }
	
return k;                            //?????k
}
