#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& prices,int fee){
    int n = prices.size();
    int inf = 1e15;
    vector<vector<int>> dp(n+1,vector<int>(2, 0));
    dp[0][1] = -inf;
    for (int i = 1; i <= n;i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i-1] - fee);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i-1]);
    }
    return dp[n][0];
}
signed main(){
    int n, fee;
    cin >> n >> fee;
    vector<int> prices(n);
    for (int i = 0; i < n;i++)
        cin >> prices[i];
    int ans = solve(prices,fee);
    cout << "Answer : " << ans << endl;
    return 0;
}