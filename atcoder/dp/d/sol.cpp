#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n, w;
    int maxw = 1e5 + 5;
    cin >> n >> w;
    vector<int> prices(n);
    vector<int> wt(n);
    for (int i = 0; i < n;i++)
        cin >>wt[i]>> prices[i];
    vector<vector<int>> dp(n + 1, vector<int>(maxw, 0));
    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= maxw;j++){
            dp[i][j] = dp[i - 1][j];
            if(wt[i-1]<=j)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - wt[i - 1]]+prices[i-1]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= w;i++)
        ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}