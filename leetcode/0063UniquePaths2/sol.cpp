#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n,m;
    cin >> n >> m;
    int dp[n][m];
    vector<vector<int>> obstacleGrid(n, vector<int>(m, 0));
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> obstacleGrid[i][j];
        }
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            dp[i][j] = 0;
            if(obstacleGrid[i][j]==1)
                dp[i][j] = 0;
            else if(i>0 || j>0){
                if(i>0)
                    dp[i][j] += dp[i - 1][j];
                if(j>0)
                    dp[i][j] += dp[i][j - 1];
            }
            else
                dp[i][j] = 1;
        }
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
        cout << dp[n - 1][m - 1] << endl;
    return 0;
}