#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int a,b,c;
    cin>>a>>b>>c;
    char ans='A';
    if(b<a && b<c)
        ans='B';
    if(c<a && c<b)
        ans='C';
    cout<<ans<<endl;
    return 0;
}