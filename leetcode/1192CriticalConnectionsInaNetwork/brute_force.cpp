#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
void dfs(int u,vector<bool>& visited,vector<vector<int>>& g){
    visited[u] = true;
    for(auto v:g[u]){
        if(visited[v])
            continue;
        dfs(v, visited, g);
    }
}
vector<vector<int>> solve(vector<vector<int>>& edges,int n){
    int m = edges.size();
    vector<vector<int>> g(n);
    vector<vector<int>> ans;
    vector<bool> visited(n);
    for (int i = 0; i < m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        g[u].erase(find(g[u].begin(), g[u].end(), v));
        g[v].erase(find(g[v].begin(), g[v].end(), u));
        visited.clear();
        visited.resize(n, false);
        dfs(0, visited, g);
        for (int j = 0; j < n;j++)
            if (visited[j] == false){
                ans.push_back(edges[i]);
                break;
            }
        g[u].push_back(v);
        g[v].push_back(u);
    }
    return ans;
}
signed main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        vector<int> tmp;
        tmp.push_back(u);
        tmp.push_back(v);
        edges.push_back(tmp);
    }
    vector<vector<int>> ans = solve(edges,n);
    for (int i = 0; i < ans.size();i++)
        cout << ans[i][0] << " " << ans[i][1] << endl;
    return 0;
}