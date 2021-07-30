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
        vector<int> left(n),right(n);
        left[0] = dp[i - 1][0];
        right[n-1] = dp[i - 1][n - 1]-n+1;
        for (int k = 1;k<n;k++)
            left[k] = max(left[k - 1], dp[i - 1][k] + k);
        for (int k = n - 2; k >= 0;k--)
            right[k] = max(right[k + 1], dp[i - 1][k] - k);
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = max(left[j]-j, right[j]+j) + grid[i][j];
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