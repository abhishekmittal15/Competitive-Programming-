#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
vector<ll> solve(ll n){
    vector<ll> result;
    result.push_back(0);
    result.push_back(1);
    for (ll i = 2; i <=n;i++){
        result.push_back(result[i / 2] + (i % 2));
    }
    return result;
}
signed main(){
    ll n;
    cin>>n;
    vector<ll> ans = solve(n);
    for (ll i = 0; i < ans.size();i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
