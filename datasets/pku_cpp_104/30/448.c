//**************************************** 
//* ????10.13??3?7??????? **
//* ?????     ???1000012888     **
//**************************************** 
int main( )                //??? 
{                          //????? 
    int i,n,sum = 0;       //?????????i?????n??????sum???????? 
    cin >> n ;             //?????n?n<100 
    for (i = 1;i <= n;i++) //???? 
    {
        if(i % 7 == 0)     //i??7????sum?? 
        sum = sum + 0;
        else if(0 <= i - 70 && i - 70 <= 9)//i?????????????????7? 
        sum = sum + 0;                     //sum??? 
        else if((i - 7) % 10 == 0)         
        sum = sum + 0;                     
        else                               //i?7??? 
        sum = sum + i * i;                 //sum??i??? 
    } 
    cout << sum << endl ;                  //??sum 
    return 0;
}                                          //?????  