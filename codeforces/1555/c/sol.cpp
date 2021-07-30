#include<iostream>
#include<vector>
using namespace std;
#define int long long int
signed main(){
    int t;
    cin>>t;
    while(t--){
        int m;
        int ans = 1000 * 1000 * 1000 + 7;
        cin>>m;
        vector<int> pref1(m + 1, 0),pref2(m+1,0);
        vector<vector<int>> c(2, vector<int>(m));
        for (int i = 1; i <=m;i++){
            cin >> c[0][i - 1];
            pref1[i] = pref1[i - 1] + c[0][i - 1];
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> c[1][i - 1];
            pref2[i] = pref2[i - 1] + c[1][i - 1];
        }
        for (int i = 1; i <= m;i++){
            int a= pref1[i] + pref2[m] - pref2[i - 1];
            int b = max(pref1[m] - pref1[i], pref2[i - 1]);
            ans = min(ans, b);
        }
        cout << ans << endl;
    }
    return 0;
}