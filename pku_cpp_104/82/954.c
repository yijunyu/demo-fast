/*
 *    Filename:3.4NormalBloodpressure.cpp
 *
 *  Created on: 2012-10-22
 *      Author: ???
 *    Function:????????????????
 */

int main()
{
	int n,a,b,i=0,h=0;//n??????a?b???????????,i?k?????h???????????
	cin>>n;
	while(n!=0)//??????n??
	{cin>>a >>b;
	if(a>=90 && a<=140 && b>=60 && b<=90)
	   i++;          //?????i+1
	else
	      i=0;     //??????i????
	if(h<=i)
		h=i;         //??h?????????
	   n--;
	  	}
     cout<<h<<endl;
     return 0;
}
