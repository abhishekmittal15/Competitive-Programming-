#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int h,w;
    int mod = 1e9 + 7;
    cin >> h >> w;
    vector<vector<char>> grid(h,vector<char>(w));
    for (int i = 0;i<h;i++){
        for (int j = 0; j < w;j++)
            cin >> grid[i][j];
    }
    vector<vector<int>> dp(h+1, vector<int>(w+1, 0));
    for (int i=0;i<=h;i++)
        dp[i][0] = 0;
    for (int i = 0; i <= w; i++)
        dp[0][w] = 0;
    dp[0][1] = 1;
    for (int i = 1; i <= h;i++){
        for (int j = 1; j <= w;j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            if(grid[i-1][j-1]=='#')
                dp[i][j] = 0;
            dp[i][j] %= mod;
        }
    }
    cout << dp[h][w] << endl;
    return 0;
}