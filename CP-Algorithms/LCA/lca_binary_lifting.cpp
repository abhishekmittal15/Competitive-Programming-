#include<iostream>
#include<vector>
using namespace std;
#define int long long int
vector<vector<int>> tree;
vector<vector<int>> parent;
vector<int> tin, tout;
int timer = 0;
void dfs(int u,int p){
    parent[u][0] = p;
    tin[u] = timer++;
    for (int i = 1; i < 40;i++){
        parent[u][i] = parent[parent[u][i - 1]][i - 1];
    }
    for(auto v:tree[u]){
        if(v==p)
            continue;
        dfs(v, u);
    }
    tout[u] = timer++;
}
bool isAncestor(int u,int v){
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}
int lca(int u,int v){
    if(isAncestor(u,v))
        return u;
    if(isAncestor(v,u))
        return v;
    for (int i = 20; i >= 0;i--){
        if(!isAncestor(parent[u][i],v))
            u = parent[u][i];
    }
    return parent[u][0];
}
signed main(){
    int n;
    cin >> n;
    tree.resize(n + 1);
    tin.resize(n + 1);
    tout.resize(n + 1);
    parent.resize(n + 1, vector<int>(40));
    for (int i = 1;i<n;i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n;i++){
        cout << i;
        for (int j = 0; j < 5;j++)
            cout << "->" << parent[i][j];
        cout << endl;
    }
    int q;
    cin >> q;
    while(q--){
        int u,v;
        cin>>u>>v;
        cout << lca(u, v) << endl;
    }
    return 0;
}