#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int solve(vector<int>& a){
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n;i++){
        for (int j = i+1; j < n;j++)
            ans = max(a[j] - a[i],ans);
    }
    return ans;
}
signed main(){
    int n;
    cin>>n;
    vector<int> prices(n);
    for (int i = 0; i < n;i++){
        cin >> prices[i];
    }
    int ans = solve(prices);
    cout << "Answer : " << ans << endl;
    return 0;
}