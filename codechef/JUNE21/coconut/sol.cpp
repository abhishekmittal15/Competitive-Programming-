#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int xa,xb,Xa,Xb;
        cin>>xa>>xb>>Xa>>Xb;
        int ans=(Xa/xa+Xb/xb);
        if(Xa%xa!=0)    ans++;
        if(Xb%xb!=0)    ans++;
        cout<<ans<<endl;
    }
    return 0;
}