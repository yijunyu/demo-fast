int main()
{
   int step=0;     //step????????????????????????
   char *p,*q;     //p????????????q????????????
   char str[50];   //????????
   cin.getline(str,31,'\n');  //?????
   for(p=str;p<str+31;p++)    
   {

      if(*p<'0' || *p>'9')    //????
        continue;
      else       
      {
          for(q=p;q<str+31;q++)  //?q??p
          {
              if(*q>='0' && *q<='9')  //???????????p??????????
              {
                 step++;
                 cout<<*q;
              }
              else 
              {
                 cout<<endl;
				 p=p+step;  //p???????
				 step=0;  //??
                 break;
              }
          }
      }
	  if(*p=='\n') break;
     
   }
   return 0;
}   