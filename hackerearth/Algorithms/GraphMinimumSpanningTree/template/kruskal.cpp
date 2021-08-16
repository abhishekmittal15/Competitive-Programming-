#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
vector<int> parent;
vector<int> sz;
int f(int u){
    if(parent[u]==u)
        return u;
    return parent[u] = f(parent[u]);
}
void un(int u,int v){
    u=f(u);
    v=f(v);
    if(sz[u]>sz[v]) 
        swap(u,v);
    sz[v] += sz[u];
    parent[u] = v;
}
signed main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int, pair<int, int>>> edges;
    parent.resize(n + 1);
    sz.resize(n + 1, 1);
    for (int i = 1; i <= n;i++)
        parent[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(),edges.end());
    int cost=0;
    int cnt_edges=0;
    for(auto edge:edges){
        int w=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        if(f(u)==f(v))
            continue;
        cost+=w;
        cnt_edges++;
        un(u,v);
        if(cnt_edges==n-1)
            break;
    }
    cout<<cost<<endl;
    return 0;
}