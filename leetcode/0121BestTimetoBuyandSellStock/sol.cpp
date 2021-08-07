#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& prices){
    int lmin = 1ll * 1e9;
    int lmax = -1ll * 1e9;
    int n = prices.size();
    for (int i = 0; i < n;i++){
        lmin = min(lmin, prices[i]);
        lmax = max(lmax, prices[i]);
    }
    return lmax - lmin;
}
signed main(){
    int n;
    cin>>n;
    vector<int> prices(n);
    for (int i = 0; i < n;i++)
        cin >> prices[i];
    int ans = solve(prices);
    cout << ans << endl;
    return 0;
}