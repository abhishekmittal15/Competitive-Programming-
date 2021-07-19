#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
void dijkstra(int n,int s,int d,vector<vector<pair<int,int>>>& adj){
    int inf = 1000 * 1000 * 1000 + 7;
    vector<int> d(n, inf);
    d[s] = 0;
    for(int )
}
signed main(){
    int n,m;
    cin >> n>>m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m;i++){
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
    dijkstra(n,source,dest,adj);
    return 0;
}