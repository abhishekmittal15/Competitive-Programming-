#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int solve(vector<int>& prices){
    int n = prices.size();
    int ans = 0;
    vector<int> cur_max(n);
    cur_max[n - 1] = prices[n - 1];
    for (int i = n - 2; i >= 0;i--)
        cur_max[i] = max(cur_max[i + 1], prices[i]);
    for (int i = 0; i < n;i++)
        ans = max(ans, cur_max[i] - prices[i]);
    return ans;
}
signed main(){
    int n;
    cin>>n;
    vector<int> prices(n);
    for (int i = 0; i < n;i++)
        cin >> prices[i];
    int ans = solve(prices);
    cout << "Answer : " << ans << endl;
    return 0;
}