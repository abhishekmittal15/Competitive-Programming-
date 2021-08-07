#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& a){
    int n = a.size();
    int ans = 0;
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <=n;i++)
        pref[i]=pref[i-1]+a[i-1];
    for (int i = 1; i <= n;i++){
        int start = (n-i + 1) / 2;
        int end = (i + 1) / 2;
        ans += (end - start) * pref[i];
    }
    return ans;
}
signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0; i < n;i++)
        cin >> a[i];
    int ans = solve(a);
    cout << "Answer : " << ans << endl;
    return 0;
}