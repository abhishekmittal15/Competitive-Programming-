#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
bool solve(int n){
    vector<bool> dp(n + 1,false);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n;i++){
        for (int j = (i+1)/2; j > 0;j--)
            if(i%j==0)
                dp[i] = dp[i] | (!dp[i-j]);
    }
    return dp[n];
}
signed main(){
    int n;
    cin>>n;
    bool ans = solve(n);
    cout << "Answer : " << ans << endl;
    return 0;
}