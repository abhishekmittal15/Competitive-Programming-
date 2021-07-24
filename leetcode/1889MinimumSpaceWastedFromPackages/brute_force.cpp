#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
int solve(vector<int>& packages, vector<vector<int>>& suppliers){
    int mod = 1LL*1000 * 1000 * 1000 + 7;
    int max_lim = 1LL*1000 * 1000 * 1000 * 10 + 5;
    int ans = max_lim;
    int n = packages.size();
    int m = suppliers.size();
    for (int i = 0; i < m;i++){
        int wasted = 0;
        for (int j = 0; j < n;j++){
            int box = lower_bound(suppliers[i].begin(), suppliers[i].end(), packages[j]) - suppliers[i].begin();
            if(box==suppliers[i].size()){
                wasted = -1;
                break;
            }
            wasted += suppliers[i][box] - packages[j];
        }
        if(wasted!=-1)
            ans = min(ans, wasted);
    }
    if(ans==max_lim)
        ans = -1;
    else
        ans = (ans >= mod) ? ans - mod : ans;
    return ans;
}
signed main(){
    int n, m;
    cin >> n >> m;
    vector<int> packages(n);
    vector<vector<int>> suppliers(m);
    for (int i = 0; i < n;i++)
        cin >> packages[i];
    for (int i = 0; i < m;i++){
        int num_boxes;
        cin >> num_boxes;
        for (int j = 0,sz; j < num_boxes;j++){
            cin >> sz;
            suppliers[i].push_back(sz);
        }
    }
    int answer = solve(packages, suppliers);
    cout << "Answer : " << answer << endl;
    return 0;
}