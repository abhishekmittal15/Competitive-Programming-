#include<iostream>
using namespace std;
#define int long long int
int mod = 1000 * 1000 * 1000 + 7;
int binpow(int a,int b){
    int ans = 1;
    while(b>0){
        if(b&1)
            ans = (ans * a)%mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return (ans%mod);
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int ans = binpow(2,n)-1;
        ans = binpow(ans, m);
        cout << ans << endl;
    }
    return 0;
}