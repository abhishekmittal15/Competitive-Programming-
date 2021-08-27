#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        map<int, int> cnt;
        int mx = 0;
        for (int i = 0; i < n;i++){
            cin >> a[i];
            cnt[a[i]]++;
            mx = max(cnt[a[i]], mx);
        }
        int ans = min(n-2,n-mx);
        if(ans<0)
            ans = 0;
        cout << ans << endl;
    }
    return 0;
}