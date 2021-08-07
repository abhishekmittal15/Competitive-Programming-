#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& prices,int k){
    int ans = 0;
    int n = prices.size();
    int inf = 1e9;
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= k;i++){
        int mn = prices[0];
        for (int j = 1; j <n;j++){
            mn = min(mn, prices[j] - dp[i - 1][j - 1]);
            dp[i][j] = max(dp[i][j-1], prices[j] - mn);
        }
    }
    return dp[k][n-1];
}
signed main(){
    int n,k;
    cin>>n>>k;
    vector<int> prices(n);
    for (int i = 0; i < n;i++)
        cin >> prices[i];
    int ans = solve(prices,k);
    cout << "Answer : " << ans << endl;
    return 0;
}