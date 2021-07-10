#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    while(t--){
        int D,d,p,q;
        cin>>D>>d>>p>>q;
        int n=D/d;
        int ans = ((n*(2*p+(n-1)*q))/2)*d;
        int rem=D-(n*d);
        ans+=(p+q*n)*rem;
        cout<<ans<<endl;
    }
    return 0;
}