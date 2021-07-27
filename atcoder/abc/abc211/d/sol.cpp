#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define int long long int 
int bfs(int n,vector<vector<int>>& g){
    int dist = 0;
    queue<int> q;
    vector<bool> visited(n + 1, false);
    q.push(1);
    while(q.empty()==false){
        int u = q.front();
        q.pop();
        dist++;
        for (int j = 0; j < g[u].size();j++){
            if(visited[g[u][j]])
                continue;
            if(g[u][j]==n)
                return dist;
            q.push(g[u][j]);
        }
    }
    return dist;
}
signed main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int shdist = bfs(n,g);
    
    return 0;   
}