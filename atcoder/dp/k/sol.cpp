#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n,k;
    cin >> n >> k;
    vector<int> stones(n + 1);
    for (int i = 0;i<n;i++)
        cin >> stones[i];
    vector<bool> dp(k + 1);
    dp[0] = 0;
    for (int i = 1; i <= k;i++){
        dp[i] = 1;
        for (int j = 0; j < n;j++){
            if(i>=stones[j])
                dp[i] = dp[i] & dp[i - stones[j]];
        }
        dp[i] = 1-dp[i];
    }
    if(dp[k])
        cout << "First" << endl;
    else
        cout << "Second" << endl;
    // cout << dp[k] << endl;
    return 0;
}