#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n,w;
    cin >> n >> w;
    vector<int> prices(n);
    vector<int> wt(n);
    int maxv = -1;
    for (int i = 0; i < n;i++){
        cin >> wt[i] >> prices[i];
        maxv = max(maxv, prices[i]);
    }
    maxv = n * maxv;
    int inf = 1e15;
    vector<vector<int>> dp(n + 1, vector<int>(maxv+1, inf));
    for (int i = 0; i <= n;i++)
        dp[i][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxv; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= prices[i - 1])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - prices[i - 1]] + wt[i - 1]);
        }
    }
    int ans = 0;
    for (int i = maxv; i >= 0;i--)
        if(dp[n][i]<=w){
            ans = i;
            break;
        }
    cout << ans << endl;
    return 0;
}