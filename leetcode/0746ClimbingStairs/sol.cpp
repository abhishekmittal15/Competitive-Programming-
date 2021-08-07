#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& cost){
    int n = cost.size();
    int ans = 0;
    vector<int> dp(n+2);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <=(n+1);i++){
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return min(dp[n], dp[n + 1]);
}
signed main(){
    int n;
    cin>>n;
    vector<int> cost(n);
    for (int i = 0; i < n;i++){
        cin >> cost[i];
    }
    int ans = solve(cost);
    cout << "Answer : " << ans << endl;
    return 0;
}