#include <iostream>
#include <vector>
using namespace std;
#define int long long int
int maxn=51;
int maxk = 25;
int inf = 1e17;
int f(int l, int r, vector<int> &a, int k, int x, vector<vector<vector<int>>> &dp)
{
    if(l>r)
        return 0;
    if(dp[l][r][k]!=-1)
        return dp[l][r][k];
    int choice1 = a[l] + f(l + 1, r, a, k, x,dp);
    int choice2 = a[r] + f(l, r - 1, a, k, x,dp);
    int choice3 = inf;
    if(r-l>=1 and k>0)
        choice3 = x + f(l + 1, r - 1, a, k - 1, x,dp);
    dp[l][r][k] = min(choice1, min(choice2, choice3));
    return dp[l][r][k];
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k, -1)));
        int ans = f(0, n - 1, a, k, x,dp);
        cout << ans << endl;
    }
    return 0;
}