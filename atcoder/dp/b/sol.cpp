#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n;i++)
        cin >> h[i];
    int inf = 1e15;
    vector<int> dp(n,inf);
    dp[0] = 0;
    for (int i = 1; i < n;i++)
        for (int j = i-k; j <i;j++)
        if(j>=0)
            dp[i] = min(dp[i], dp[j] + abs(h[j] - h[i]));
    cout << dp[n - 1] << endl;
    return 0;
}