#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin >> n;
    int mx=-1;
    int mn = 1e10;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i].first >> a[i].second;
        int pt = min(a[i].first, a[i].second);
        mn = min(mn, pt);
        mx = max(mx, pt);
    }
    cout<<mx-mn<<endl;
    return 0;
}