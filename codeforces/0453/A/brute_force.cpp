#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
#define double long double
signed main(){
    int n, m;
    cin>>m>>n;
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 1.0));
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if(i!=1)
            for (int k = 1; k <= j;k++)
                dp[i][j] += dp[i - 1][k];
            dp[i][j] /= (double)(m);
        }
    }
    double ans = 0;
    for (int i = 1; i <= m;i++)
        ans += ((double)(i)*dp[n][i]);
    cout << ans << endl;
    return 0;
}