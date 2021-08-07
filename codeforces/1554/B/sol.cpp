#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin >>t;
    while(t--){
        int n,k,ans=-1ll*1e15;
        cin>>n>>k;
        vector<int> a(n);
        for (int i = 0; i < n;i++)
            cin >> a[i];
        for (int i = n - 1; i >= max(n - 200,1ll*0);i--){
            for (int j = i - 1; j >= max(n - 200,1ll* 0); j--){
                int val = (i+1) * (j+1) - (k * (a[i] | a[j]));
                ans = max(ans, val);
            }
        }
        cout << ans << endl;
    }
    return 0;
}