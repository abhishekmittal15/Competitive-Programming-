#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int f(string s,int i,int j,vector<vector<int>>& dp){
    if(i==j)
        return 1;
    if(j-i==1 && s[i]==s[j])
        return 2;
    else
        return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ret = 0;
    if(s[i]==s[j])
        ret = dp[i + 1][j - 1] + 2;
    else
        ret = max(f(s, i + 1, j, dp), f(s, i, j - 1, dp));
    return dp[i][j] = ret;
}
int solve(string s){
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n,-1));
    int ans = f(s,0,n-1, dp);
    return ans;
}
signed main(){
    string s;
    cin>>s;
    int ans = solve(s);
    cout << ans << endl;
    return 0;
}