#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        vector<int> a(n), b(n);
        for (int i = 0; i < n;i++)
            cin >> a[i], ans = max(ans, a[i]);
        for (int i = 0; i < n; i++)
            cin >> b[i];
        vector<pair<int, int>> times(n+1);
        times[0] = {0, 0};
        for (int i = 1; i <=n;i++)
            times[i] = {a[i-1], b[i-1]};
        sort(times.begin(), times.end());
        vector<int> sum(n + 1);
        sum[0] = 0;
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + times[i].second;
        for (int i = 1; i <= n;i++){
            int cur_time = max(sum[n] - sum[i-1], times[i-1].first);
            // cout << i << " " << cur_time << endl;
            ans = min(ans, cur_time);
        }
        cout << ans << endl;
    }
    return 0;
}