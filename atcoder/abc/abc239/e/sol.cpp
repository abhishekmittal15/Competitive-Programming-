#include<bits/stdc++.h>
using namespace std;

void lol(int i, int p, vector<vector<int>> &graph, vector<int> &vals, vector<vector<int>> &dp) {
    vector<int> v = {vals[i]};

    for (auto &n : graph[i]) {
        if (n == p) continue;
        lol(n, i, graph, vals, dp);
        v.insert(v.end(), dp[n].begin(), dp[n].end());
    }
    sort(v.rbegin(), v.rend());
    for (int j=0; j<min(20, (int)v.size()); j++)
        dp[i][j] = v[j];
}

int main() {
    int n,q;
    cin>>n>>q;
    vector<int> vals(n);
    vector<vector<int>> graph(n);
    for(int i=0;i<n;i++){
        cin>>vals[i];
    }
    for(int i=0,a,b;i<(n-1);i++){
        cin>>a>>b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    vector<vector<int>> dp(n, vector<int>(20, INT_MIN));
    lol(0, -1, graph, vals, dp);

    for(int i=0,v,k;i<q;i++){
        cin>>v>>k;
        cout << dp[v-1][k-1] << endl;
    }

    return 0;
}