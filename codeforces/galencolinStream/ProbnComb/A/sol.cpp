#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
#define one 1ll
signed main(){
    int n, m;
    cin>>n>>m;
    int ans=0;
    vector<vector<int>> table(n, vector<int>(m, 0));
    for (int i = 0;i<n;i++){
        for (int j = 0; j < m;j++)
            cin >> table[i][j];
    }
    for (int i = 0; i < n;i++){
        int cnt1 = 0;
        int cnt0 = 0;
        for (int j = 0; j < m;j++){
            int cur = table[i][j];
            if(cur)
                cnt1++;
            else
                cnt0++;
        }
        ans += ((one << cnt1) + (one << cnt0) - 2);
    }
    // cout << ans << endl;
    for (int i = 0; i < m; i++)
    {
        int cnt1 = 0;
        int cnt0 = 0;
        for (int j = 0; j < n; j++)
        {
            int cur = table[j][i];
            if (cur)
                cnt1++;
            else
                cnt0++;
        }
        ans += ((one << cnt1) + (one << cnt0) - 2);
    }
    cout << ans-(n*m) << endl;
    return 0;
}