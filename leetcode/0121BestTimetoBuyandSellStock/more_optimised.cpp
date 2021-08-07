#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& prices){
    int cur_min = 1ll * 1e9;
    int ans = 0;
    int n = prices.size();
    for (int i = 0; i < n;i++){
        ans = max(ans, prices[i] - cur_min);
        cur_min = min(cur_min, prices[i]);
    }
    return ans;
}
signed main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n;i++)
        cin >> prices[i];
    int ans = solve(prices);
    cout << "Answer : " << ans << endl;
    return 0;
}