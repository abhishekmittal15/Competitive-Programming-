#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
vector<pair<int,pair<int,int>>> edges;
vector<int> parent;
vector<int> sz;
int f(int u){
    if(parent[u]==u)
        return u;
    return parent[u] = f(parent[u]);
}
void un(int u,int v){
    u = f(u);
    v = f(v);
    if(sz[u]>sz[v]) 
        swap(u,v);
    sz[v]+=sz[u];
    parent[u] = v;
}
signed main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> cost(k+1);
    parent.resize(n+1);
    sz.resize(n+1,1);
    for (int i = 1;i<=n;i++)
        parent[i] = i;
    for (int i = 1; i <= k; i++)
    {
        cin >> cost[i];
    }
    for (int i = 0;i<m;i++){
        int u,v,l,w=0;
        cin>>u>>v>>l;
        for (int j= 0;j<l;j++){
            int token;
            cin>>token;
            w =w| 1ll<<(token);
        }
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    int ans=0;
    int cnt_edges = 0;
    for(auto edge:edges){
        int w=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        if(f(u)==f(v)){
            continue;
        }
        ans=ans|w;
        cnt_edges++;
        un(u, v);
        if(cnt_edges==(n-1))
            break;
    }
    if(cnt_edges!=(n-1)){
        cout << -1 << endl;
        return 0;
    }
    int cst = 0;
    for (int i =1; i <=k;i++){
        if(ans&(1ll<<i))
            cst += cost[i];
    }
    cout << cst << endl;
    return 0;
}