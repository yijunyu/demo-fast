int main(){
	int x,y,i;//???????i??????
	cin>>x>>y;//??????x,y
	for(i=0;;i++){//??????????
		if(x==y){cout<<x<<endl;break;}//?x,y?????????????
		if(x>y){x=x/2;continue;}//????????????2???????????
		if(x<y) y=y/2;
	}
	return 0;//????
}


