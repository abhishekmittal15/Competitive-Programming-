#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
int solve(vector<int>& coins,int amt){
    int n = coins.size();
    int dp[amt + 1];
    int inf = 1ll * 1e9;
    dp[0] = 0;
    sort(coins.begin(), coins.end());
    for (int i = 1; i <=amt;i++){
        dp[i] = inf;
        for (auto val:coins){
            if(val>i)
                break;
            dp[i] = min(dp[i], 1 + dp[i - val]);
        }
    }
    return dp[amt] == inf ? -1 : dp[amt];
}
signed main(){
    int n,amt;
    cin >> n >> amt;
    vector<int> coins(n);
    for (int i = 0; i < n;i++)
        cin >> coins[i];
    int ans = solve(coins, amt);
    cout << "Answer : " << ans << endl;
    return 0;
}