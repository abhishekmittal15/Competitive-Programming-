#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& prices){
    int n = prices.size();
    int inf = 1e9;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2, 0)));
    dp[0][1][0] =-inf;
    dp[0][1][1] = -inf;
    
}
signed main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0;i<n;i++)
        cin >> prices[i];
    int ans = solve(prices);
    cout << "Answer : " << ans << endl;
    return 0;
}