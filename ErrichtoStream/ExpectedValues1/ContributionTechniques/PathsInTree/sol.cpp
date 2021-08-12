#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int ans = 0;
int n;
vector<vector<int>> tree;
vector<int> sz;
int dfs1(int u,int p){
    sz[u] = 1;
    for(auto v:tree[u]){
        if(v==p)
            continue;
        sz[u] += dfs1(v, u);
    }
    return sz[u];
}
void dfs2(int u,int p){
    for(auto v:tree[u]){
        if (p == v) 
            continue;
        ans += (sz[v] * (n - sz[v]));
        dfs2(v, u);
    }
}
signed main(){
    cin>>n;
    tree.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 1; i < n;i++){
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    cout << ans << endl;
    return 0;
}