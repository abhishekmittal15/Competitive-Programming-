#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans = 0;
        int mx = 1e5 + 6;
        vector<int> cnt(mx);
        for (int i = 0;i<n;i++){
            int a;
            cin >> a;
            cnt[a]++;
        }
        for (int i = 2;i<mx;i++)
            ans += (cnt[i] > (i - 1)) ? (i - 1) : cnt[i];
        cout << ans << endl;
    }
    return 0;
}