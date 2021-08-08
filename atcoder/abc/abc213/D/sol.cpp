#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int
vector<vector<int>> tree;
vector<bool> visited;
void dfs(int u){
    cout<<u<<" ";
    visited[u] = true;
    for (int i = 0; i < tree[u].size();i++){
        int v = tree[u][i];
        if(visited[v])
            continue;
        dfs(v);
        cout << u << " ";
    }
} 
signed main(){
    int n;
    cin>>n;
    tree.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i = 1;i<n;i++){
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for (int i = 1;i<=n;i++){
        if((int)(tree[i].size())>0)
            sort(tree[i].begin(), tree[i].end());
    }
    dfs(1);
    return 0;
}