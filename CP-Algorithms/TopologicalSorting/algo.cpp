#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
void dfs(int u,vector<vector<int>>& g,vector<bool>& visited,vector<int>& ans){
    visited[u] = true;
    for (auto v:g[u]){
        if(visited[v])
            continue;
        dfs(v, g, visited, ans);
    }
    ans.push_back(u);
}
vector<int> topological_sorting(vector<vector<int>>& g){
    int n = g.size();
    vector<bool> visited(n);
    vector<int> ans;
    dfs(0, g, visited, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}
signed main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    vector<int> ans = topological_sorting(g);
    for (int i = 0; i < n;i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}