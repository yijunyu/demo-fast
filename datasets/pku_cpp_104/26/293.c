/**
 *???1.cpp
 *??????
 *??????????
 *???12?10?
 */
int main()
{
	char a[101];
	gets(a);     //?????
	char*q=a;     //???????????
	for(q=a+2;*q!='\0';q++) //??????????
	{
		if(*q==' ' && *(q-1)==' ')//???2????
		{
			char*qq=q; //???2??????
			while(*(q+1)!='\0')
			{
				*(q++)=*(q+1);  //????????????
			}
			*q='\0';   //????????????
			q=qq-1;   //????????????????
		}
	}
	q=a;          //???????????????
	cout<<q<<endl;
	return 0;
}