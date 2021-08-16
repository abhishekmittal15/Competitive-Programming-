#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
vector<vector<int>> tree;
vector<vector<int>> parent;
void dfs(int u,int p){
    parent[u][0] = p;
    for (int i= 1; i < 40;i++){
        parent[u][i] = parent[parent[u][i - 1]][i - 1];
    }
    for(auto v:tree[u]){
        if(v==p)
            continue;
        dfs(v, u);
    }
}
int lca(int u,int v){
    
}
signed main(){
    int n;
    cin>>n;
    tree.resize(n + 1);
    parent.resize(n + 1, vector<int>(40,0));
    for (int i = 1;i<n;i++){
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0);
    int q;
    cin >> q;
    while(q--){
        int r, u, v;
        cin >> r >> u >> v;
        int x = lca(u,v);
        int y = lca(u, r);
        int z = lca(v, r);
        if(y!=x && z==x)
            cout <<y<< endl;
        if(y==x && z!=x)
            cout << z << endl;
        if(y==x && z==x)
            cout << x << endl;
    }
    return 0;
}