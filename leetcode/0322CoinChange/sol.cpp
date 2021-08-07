#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& coins,int amt){
    int inf = 1ll * (1e9);
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amt + 1, inf));
    for (int i = 0; i <= n;i++)
        dp[i][0] = 0;
    for (int i = 1; i <=n;i++){
        for (int j = 1; j <= amt;j++){
            dp[i][j] = dp[i - 1][j];
            if(j>=coins[i-1])
                dp[i][j]=min(dp[i][j],1+min(dp[i-1][j-coins[i-1]],dp[i][j-coins[i-1]]));
        }
    }
    return (dp[n][amt] == inf) ? -1 : dp[n][amt];
}
signed main(){
    int n,amt;
    cin>>n>>amt;
    vector<int> coins(n);
    for (int i = 0; i < n;i++){
        cin >> coins[i];
    }
    int ans = solve(coins,amt);
    cout << "Answer : " << ans << endl;
    return 0;
}