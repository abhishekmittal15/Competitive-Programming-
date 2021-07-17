#include<bits/stdc++.h>
using namespace std;
#define int long long int
int solve(string s,string t){
    int n = s.length();
    int m = t.length();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= m;i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            dp[i][j] = dp[i - 1][j];
            if(s[i-1]==t[j-1])
                dp[i][j] += dp[i - 1][j - 1];
        }
    }
    return dp[n][m];
}
signed main(){
    string s, t;
    cin>>s>>t;
    int answer = solve(s, t);
    cout << "Answer: " << answer << endl;
    return 0;
}