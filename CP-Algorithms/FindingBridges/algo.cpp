#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int timer = 0;
void dfs(int u,int p,vector<int>& low,vector<int>& disc,vector<vector<int>>& g,vector<bool>& visited,vector<vector<int>>& ans){
    visited[u] = true;
    disc[u] = low[u] = timer++;
    for(auto v:g[u]){
        if(v==p)
            continue;
        if(visited[v])
            low[u] = min(low[u], disc[v]);  // we are updating the lowest discovery time of the current vertex
        else{
            dfs(v, u, low, disc, g, visited, ans);
            low[u] = min(low[u], low[v]); // We are updating the lowest discovery time of the current vertex 
            if(low[v]>disc[u])
            { // We have discovered the bridge
                vector<int> tmp;
                tmp.push_back(u); 
                tmp.push_back(v);
                ans.push_back(tmp);
            }
        }
    }
}
vector<vector<int>> bridges(vector<vector<int>>& g){
    int n = g.size();
    vector<bool> visited(n, false);
    vector<int> low(n, 0);
    vector<int> disc(n, 0);
    vector<vector<int>> ans;
    dfs(0, -1, low, disc, g, visited, ans);
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
        g[v].push_back(u);
    }
    vector<vector<int>> ans = bridges(g);
    cout << "These are the following bridges" << endl;
    for (int i = 0; i < ans.size();i++){
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}