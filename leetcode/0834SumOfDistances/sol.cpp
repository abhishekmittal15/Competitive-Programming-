#include<iostream>
#include<vector>
using namespace std;
#define int long long int
void dfs(int v, int p,vector<vector<int>>& graph, vector<int> &sz){
    sz[v] = 1;
    for(auto child:graph[v]){
        if(child==p)
            continue;
        dfs(child, v, graph, sz);
        sz[v] += sz[child];
    }
}
int solve(int n, vector<vector<int>> &graph)
{
    vector<int> sz(n);
    // vector<int> sum(n+1);
    dfs(0, -1, graph, sz);
    for(int i=0;i<n;i++){
        cout << i << " " << sz[i] << endl;
    }
    return 0;
}
signed main(){
    int n;
    cin>>n;
    vector<vector<int>> graph(n);
    for (int i = 0,u,v; i < (n - 1);i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans = solve(n,graph);
    cout << "Answer : " << ans << endl;
    return 0;
}