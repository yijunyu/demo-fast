//**************************
//*?????3?5?7????**
//*?????? 1200012888 **
//*???2012.09.25**
//**************************
int main()
{
	int N;											//????N
	cin>>N;											//????N
	if (N%3==0&&N%5==0&&N%7==0)						
	{
		cout<<"3"<<" "<<"5"<<" "<<"7"<<endl;
	}	
	//????3?5?7???????3 5 7???????????
	else if (N%3!=0&&N%5==0&&N%7==0)
	{
		cout<<"5"<<" "<<"7"<<endl;
	}
	else if (N%3==0&&N%5!=0&&N%7==0)
	{
		cout<<"3"<<" "<<"7"<<endl;
	}
	else if (N%3==0&&N%5==0&&N%7!=0)
	{
		cout<<"3"<<" "<<"5"<<endl;
	}
	//?????????????????????????????3 5?? 3 7??5 7,????????
	else if (N%3==0&&N%5!=0&&N%7!=0)
	{
		cout<<"3"<<endl;
	}
	else if (N%3!=0&&N%5==0&&N%7!=0)
	{
		cout<<"5"<<endl;
	}
	else if (N%3!=0&&N%5!=0&&N%7==0)
	{
		cout<<"7"<<endl;
	}
	//?????????????????
	else
	{
		cout<<"n"<<endl;
	}
	//????????????????n)
	return 0;
}