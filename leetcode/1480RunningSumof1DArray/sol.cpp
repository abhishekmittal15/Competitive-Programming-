#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
vector<int> solve(vector<int>& a){
    int n = a.size();
    vector<int> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n;i++)
        pref[i] = pref[i - 1] + a[i];
    return pref;
}
signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];
    vector<int> ans = solve(a);
    for (int i = 0; i < n;i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
