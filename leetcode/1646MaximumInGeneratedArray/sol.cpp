#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(int n){
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n;i++){
        dp[i] = dp[i / 2];
        if(i%2)
            dp[i] += dp[i / 2 + 1];
    }
    return dp[n];
}
signed main(){
    int n;
    cin>>n;
    int ans = solve(n);
    cout << "Answer : " << ans << endl;
    return 0;
}