#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int mod = 1e9 + 7;
signed main(){
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    if(n<8){
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int>> dp(n+1,vector<int>(8,0));
    for (int i = 1; i <= n; i++)
    {
        char cur = s[i - 1];
        for (int j = 0; j < 8;j++)
            dp[i][j] = dp[i - 1][j];
        if (cur == 'c')
            dp[i][0]++;
        if(cur=='h')
            dp[i][1] += dp[i - 1][0];
        if(cur=='o')
            dp[i][2] += dp[i - 1][1];
        if(cur=='k')
            dp[i][3] += dp[i - 1][2];
        if(cur=='u')
            dp[i][4] += dp[i - 1][3];
        if(cur=='d')
            dp[i][5] += dp[i - 1][4];
        if(cur=='a')
            dp[i][6] += dp[i - 1][5];
        if(cur=='i')
            dp[i][7] += dp[i - 1][6];
        for (int j = 0; j < 8;j++)
            dp[i][j] %= mod;
    }
    cout << dp[n][7] << endl;
    return 0;
}