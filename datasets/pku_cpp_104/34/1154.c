
int i;
void Kakutan()
{
    while(i!=1)
    {
        if(i%2==1)
        {
            cout<<i<<"*3+1="<<i*3+1<<endl;
            i=i*3+1;
        }
        else
        {
            cout<<i<<"/2="<<i/2<<endl;
            i=i/2;
        }
    }
    if(i==1)cout<<"End"<<endl;
    return;
}
int main()
{
    cin>>i;
    Kakutan();
    return 0;
}