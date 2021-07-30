#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& a){
    int ans = 0;
    int n = a.size();
    for (int i = 0;i<(n-1);i++)
        ans = max(ans, a[i] * a[i + 1]);
    return ans;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n;i++)
            cin >> a[i];
        int ans = solve(a);
        cout << ans << endl;
    }
    return 0;
}