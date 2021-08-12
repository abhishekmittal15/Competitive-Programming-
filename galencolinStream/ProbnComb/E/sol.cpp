#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,t;
    double p;
    cin>>n>>p>>t;
    vector<vector<double>> dp(n + 1, vector<double>(t+1, 0.0));
    dp[0][0] = (1 - p);
    for (int i =1;i<=t;i++)
        dp[0][i] = dp[0][i - 1] * (1 - p);
    dp[1][1]=p;
    for (int i = 1;i<=n;i++){
        for (int j = 2; j <= min(t,i);j++){
            dp[i][j] = dp[i - 1][j - 1] * p + dp[i][j - 1];
        }
    }
    double ans = 0.0;
    for (int i = 1;i<=n;i++){
        ans += dp[i][t];
    }
    cout << ans << endl;
}