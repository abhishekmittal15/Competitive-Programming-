#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin>>n;
    vector<vector<int>> act(n,vector<int>(3));
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    for (int i = 0; i < n;i++){
        cin >> act[i][0] >> act[i][1] >> act[i][2];
    }
    for (int i = 1; i <= n;i++){
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + act[i - 1][0];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + act[i - 1][1];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + act[i - 1][2];
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
    return 0;
}