int main()
{
	int a[6][6];//??????a[6][6]
	int i,j,t=0;//??????i,j,????t
	int max[6],min[6],row[6]={1,1,1,1,1,1},colum[6]={1,1,1,1,1,1};//????????max[6],??????min[6]???row,??colum
	for(i=1;i<=5;i++)//?????a[6][6]
	{
		for(j=1;j<=5;j++)
		{
			cin>>a[i][j];
			max[i]=a[i][1];//????????a[i][1]
			min[j]=a[1][j];//????????a[1][j]
		}
	}
	for(i=1;i<=5;i++)//????????5?????
	{
		for(j=2;j<=5;j++)
		{
			if(a[i][j]>max[i])
			{
				max[i]=a[i][j];//??i??????max[i]
				colum[i]=j;//??i???????????colum[i]
			}
		}
	}
	for(j=1;j<=5;j++)//????
	{
		for(i=2;i<=5;i++)
		{
			if(a[i][j]<min[j])
			{
				min[j]=a[i][j];
				row[j]=i;
			}
		}
	}
	for(i=1;i<=5;i++)//?????5?????5????????
	{
		for(j=1;j<=5;j++)
		{
			if(max[i]==min[j])//??i???????j????
			{
				cout<<row[j]<<' '<<colum[i]<<' '<<max[i]<<endl;//???row[j]?colum[i]?????
				t=t+1;//t?1
				break;//????
			}
		}
	}
	if(t==0)//?t=0
		cout<<"not found"<<endl;//??not found
	return 0;
}
