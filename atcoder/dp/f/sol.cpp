#include<iostream>
#include<vector>
using namespace std;
#define int long long int
signed main(){
    string s, t;
    cin>>s>>t;
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1,0));
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(s[i-1]==t[j-1])
                dp[i][j] = max(dp[i][j],1 + dp[i - 1][j - 1]);
        }
    }
    cout << dp[n - 1][m - 1] << endl;
    return 0;
}