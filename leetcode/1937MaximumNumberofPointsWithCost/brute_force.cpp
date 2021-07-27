#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ans = 0;
    for (int i = 0; i < n;i++)
        dp[0][i] = grid[0][i];
    for (int i = 1; i < m;i++){
        for (int j = 0; j < n;j++){
            for (int k = 0; k < n;k++){
                dp[i][j] = max(dp[i][j], dp[i - 1][k] - abs(j - k)+grid[i][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[m - 1][i]);
    return ans;
}
signed main(){
    int n,m;
    cin >> m >>n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++)
            cin >> grid[i][j];
    }
    int answer = solve(grid);
    cout << "Answer : " << answer << endl;
    return 0;
}