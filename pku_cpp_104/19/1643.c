int main()
{char a[101]={0},b[100]={0},c[100]={0};//???????a??????b?????c????????
int i,j,k,m,count=0;//i,j,k,m????????count????
int x,y;
int al,bl,cl;
cin.getline(a,100);
cin.getline(b,100);
cin.getline(c,100);
al=strlen(a);//??????????
bl=strlen(b);
cl=strlen(c);
for(i=0;i<=100;i++)
    {for(j=0;j<bl;j++)
    	{if (a[i+j]==b[j])//?a???b????????????????????+1
    		count++;}//????=b?????????????b?????????????????????0
            x=((i>0)&&(a[i-1]==' ')&&((a[i+bl]==' ')||a[i+bl]==(char)0)); //?????????????????????
        	y=((i==0)&&((a[i+bl]==' '||a[i+bl]==(char)0))); //???????????????
        	if(count==bl&&(x||y))//?????????a???????????
            {if(bl>=cl)//?????????
            	{for(k=0;k<cl;k++)
            		a[i+k]=c[k];//??????????????????????
                for(m=i+cl;m<al-cl;m++)
                	a[m]=a[m-cl+bl];}//?????????
            else//??????????????
                {for(m=100;m>=i+cl;m--)
                	a[m]=a[m-(cl-bl)];//?????????????c??
                for(k=0;k<cl;k++)//???c
                	a[i+k]=c[k];

                }

            }

    count=0;
    }
cout<<a;
}
