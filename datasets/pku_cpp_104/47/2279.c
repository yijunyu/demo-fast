/*
 * nixu.cpp
 *
 *  Created on: 2012-11-5
 *      Author: alias
 */
int main(){//???
	int n;//????n
	cin>>n;//??n
	int a[n];//????
	for(int i=0;i<n;i++)//????????
		cin >>a[i];
	int m;
	for(int j=0;j<n/2;j++){//?n/2??????????
		m=a[j];
		a[j]=a[n-j-1];
		a[n-j-1]=m;
	}
	for(int k=0;k<n;k++){//??????????
		if(k==0)
			cout<<a[k];
		else
			cout<<" "<<a[k];
	}
	return 0;
}

