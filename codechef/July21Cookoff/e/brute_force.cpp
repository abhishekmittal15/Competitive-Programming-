#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int max_ai = 1e3 + 5;
int solve(vector<int>& a,int k){
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(k + 1));
    for (int i = 0; i <= k;i++)
        dp[0][i] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (a[prev] != a[i] && j > 0)
                    dp[i][j] = max(1+dp[prev][j - 1], dp[i][j]);
                else if(a[prev]==a[i])
                    dp[i][j] = max(dp[i][j], dp[prev][j]+1);
            }
        }
    }
    return dp[n - 1][k];
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = solve(a,k);
        cout << ans << endl;
    }
    return 0;
}