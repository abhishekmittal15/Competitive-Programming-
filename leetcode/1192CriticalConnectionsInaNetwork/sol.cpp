#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int timer = 0;
void dfs(int u,int p,vector<bool>& visited,vector<int>& low,vector<int>& disc,vector<vector<int>>& g,vector<vector<int>>& ans){
    visited[u] = true;
    disc[u] = low[u] = timer++;
    for(auto v:g[u]){
        if(v==p)
            continue;
        if(visited[v]==true)
            low[u] = min(low[u], disc[v]);
        else{
            dfs(v, u, visited,low, disc, g, ans);
            low[u] = min(low[v], low[u]);
            if(low[v]>disc[u]){
                vector<int> tmp;
                tmp.push_back(u);
                tmp.push_back(v);
                ans.push_back(tmp);
            }
        }
    }
}
vector<vector<int>> solve(int n,vector<vector<int>>& edges){
    vector<vector<int>> g(n);
    for (int i = 0; i < edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> visited(n);
    vector<int> low(n);
    vector<int> disc(n);
    vector<vector<int>> ans;
    dfs(0, -1,visited, low, disc, g, ans);
    return ans;
}
signed main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        edges[i].push_back(u);
        edges[i].push_back(v);
    }
    vector<vector<int>> ans = solve(n, edges);
    for (int i = 0; i<ans.size();i++){
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}