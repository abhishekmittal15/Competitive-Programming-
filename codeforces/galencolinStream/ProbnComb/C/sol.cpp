#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    map<int, int> last;
    for (int i = 0;i<n;i++){
        cin >> a[i];
        last[a[i]] = i;
    }
    int group_end = 0, cnt = 0;
    for (int i = 0; i < n;i++){
        group_end = max(group_end, last[a[i]]);
        if(i==group_end){
            group_end++;
            cnt++;
        }
    }
    int ans = 1;
    int mod = 998244353;
    for (int i = 1; i < cnt; i++)
    {
        ans = (ans * 2) % mod;
    }
    cout << ans << endl;
    return 0;
}