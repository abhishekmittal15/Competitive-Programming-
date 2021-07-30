#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& a,int k){
    int n = a.size();
    int ans = -1ll * (1e9 + 7);
    for (int i = 1; i <= n;i++){
        for (int j = i + 1; j <= n;j++)
            ans = max(ans, i * j - k * (a[i - 1] | a[j - 1]));
    }
    return ans;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for (int i = 0; i < n;i++)
            cin >> a[i];
        int ans = solve(a,k);
        cout << ans << endl;
    }
    return 0;
}