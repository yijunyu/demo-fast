#include <iostream>
#include <vector>

using namespace std;


int swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
int getmenor(vector<int> v){
    for(int i=0;i<v.size();i++){
        if(v[i]>v[i+1])
            v[i]=0;
        else
            v[i+1]=0;

    }
    for(int j=0;j<v.size();j++){
    if(v[j]!=0)
        return v[0];
    }

}
void imprimir(vector<int> mv){
    for(int i=0;i<mv.size();i++){
        cout<<mv[i]<<"  ";
    }
    cout<<endl;
}


void insertionsort(vector<int> &v,int k){
    cout<<"K= "<<k<<endl;
    if(k>v.size())
        cout<<"error"<<endl;
    for(int i=0;i<k+1;i++){
        for(int j=i-1;j>=0;j--){
            if(v[j]==getmenor(v))
                break;
            swap(v[j],v[j+1]);
        }
    }
}



int main()
{

    vector <int> mv;
    mv.push_back(2);
    mv.push_back(7);
    mv.push_back(4);
    mv.push_back(3);
    mv.push_back(5);
    imprimir(mv);
    insertionsort(mv,3);
    imprimir(mv);

}
