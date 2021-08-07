#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define int long long int 
signed main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>g(n+1);
    vector<int> indegree(n+1, 0);
    vector<int> d(n + 1, 0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        indegree[v]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    for (int i = 1;i<=n;i++)
        if(indegree[i]==0)
            pq.push({0, i});
    while(pq.empty()==false){
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for (int i = 0;i<g[u].size();i++){
            if(d[g[u][i]]<dist+1){
                d[g[u][i]] = dist + 1;
                pq.push({dist + 1, g[u][i]});
            }
        }
    }
    int ans = 0;
    for (int i = 1;i<=n;i++)
        ans = max(ans, d[i]);
    cout << ans << endl;
    return 0;
}