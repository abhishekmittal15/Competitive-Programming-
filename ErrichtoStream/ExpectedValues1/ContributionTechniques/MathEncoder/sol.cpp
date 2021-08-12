#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int
int mod = 1e9 + 7;
int power(int a,int b){
    int res = 1;
    while(b>0){
        if(b&1)
            res = (res * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}
signed main(){
    int test;
    cin>>test;
    for (int t = 1; t <= test;t++){
        int n;
        cin>>n;
        int ans = 0;
        vector<int> a(n);
        for (int i = 0; i < n;i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        for (int i = 1; i <=n;i++){
            int cntmax = power(2, i-1);
            int cntmin = power(2, n-i );
            ans+=((((cntmax-cntmin)%mod)*a[i-1])%mod);
        }
        cout << "Case #"<<t<<": "<<  ans << endl;
    }
    return 0;
}