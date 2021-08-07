#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& prices){
    int n = prices.size();
    vector<vector<int>> states(n, vector<int>(4, 0));
    for (int i = 1; i <= n;i++){
        int cur_price = prices[i - 1];
        states[i][0]=max()
    }
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