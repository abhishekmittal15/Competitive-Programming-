#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
int solve(vector<int>& boxes,vector<vector<int>>& suppliers){
    int n = boxes.size();
    int m = suppliers.size();
    sort(boxes.begin(), boxes.end());
    for (int i = 0;i<m;i++)
        sort(suppliers[i].begin(), suppliers[i].end());
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n;i++)
        pref[i] = pref[i - 1] + boxes[i - 1];
    int ans = 1e15;
    for (int i = 0; i < m; i++)
    {
        int finished = 0;
        int wasted = 0;
        int cnt = 0;
        for (int j = 0; j < suppliers[i].size();j++){
            int cur = lower_bound(boxes.begin(), boxes.end(), suppliers[i][j]) - suppliers[i].begin();
            if()
            cnt += cur - finished;
            wasted += (cur - finished+1) * (pref[cur] - pref[finished]);
            finished = cur;
        }
        if(cnt==n)
            ans = min(ans, wasted);
    }
    return (ans == 1e15) ? (int)(-1) : (int)(ans);
}
signed main(){
    int n,m;
    cin>>n>>m;
    vector<int> boxes(n);
    vector<vector<int>> suppliers(m);
    for (int i = 0; i < n;i++)
        cin >> boxes[i];
    for (int i = 0; i < m;i++){
        int sz;
        cin >> sz;
        suppliers[i].resize(sz, 0);
        for (int j = 0; j < sz;j++)
            cin >> suppliers[i][j];
    }
    int ans = solve(boxes, suppliers);
    cout << "Answer : " << ans << endl;
    return 0;
}