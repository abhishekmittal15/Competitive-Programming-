// 0,0,0,1,1
// cnt1=2
// cnt0=3
// so ans=6

// 00,01,10,11
// (1<<bit)*(cnt1*(n-cnt1))+

#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n;i++)
            cin >> a[i];
        vector<int> pref(n + 1,0);
        int maxBit = 32;
        vector<int> cnt(maxBit + 1, 0);
        for (int i = 1; i <= n;i++)
            pref[i] = pref[i - 1] ^ a[i-1];
        for (int i = 0; i <= maxBit;i++){
            for (int j = 0; j < n;j++)
                if(pref[j]&(1<<i))
                    cnt[i]++;
        }
        int ans = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i <= maxBit;i++){
            int val = (1 << i) * cnt[i];
            val %= mod;
            val = val * (n - cnt[i]);
            val %= mod;
            ans += val;
            ans = ans % mod;
        }
        cout << ans << endl;
    }
    return 0;
}