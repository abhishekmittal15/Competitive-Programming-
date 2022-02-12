#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int a;
    cin>>a;
    if(a<(-1ll*(1ll<<31)) || a>((1ll<<31)-1))
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
    return 0;
}