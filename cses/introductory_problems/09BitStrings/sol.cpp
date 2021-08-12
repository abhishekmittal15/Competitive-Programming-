#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int ans = 1;
    int n;
    cin >> n;
    int a = 2;
    int mod = 1e9 + 7;
    while(n>0){
        if(n&1)
            ans = (ans * a)%mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    cout << ans << endl;
    return 0;
}