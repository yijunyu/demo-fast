
int main()  //?????
{
	int x,y,a[5],counter,i=0; //???????x?????y?????????a[5]??????counter?????i
	cin>>x; //????x
	do //????
	{
		y=x/10; //?y??x??????
		a[i]=x-y*10; //???????
		counter=i; //????
		i++; //?????1
		x=y; //y??x
		y=x*10; //??????????
	} while(y/10>0); //????
	for (i=0;i<=counter;i++) 
		cout<<a[i]; //?????
	return 0; //????
}