#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& prices){
    int n = prices.size();
    int profit = 0;
    for (int i = 1; i < n;i++)
        if(prices[i]>prices[i-1])
            profit += (prices[i] - prices[i - 1]);
    return profit;
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