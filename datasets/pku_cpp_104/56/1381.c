/*????????????9???????10??????????????1321/10=132???1??????????????132????????????????????????????????????????????????????????9????????????*/
int main ()
{
	int num;
	scanf("%d",&num);//??num
	for(num=num;num>9;num/=10){
/*?????9?????123????????????123???????????3???num=12??????????12??10???2?num=1???9??????????//???,???????*/
		printf("%d",num%10);
	}
	printf("%d",num);
	return 0;
	  }

