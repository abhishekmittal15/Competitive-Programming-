#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define int long long int 
vector<int> topological_sorting(vector<vector<int>>& g){
    int n = g.size();
    vector<int> indegree(n, 0);
    vector<int> ans;
    for (int i = 0; i < n;i++){
        for(auto u:g[i]){
            indegree[u]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n;i++){
        if(indegree[i]==0)
            q.push(i);
    }
    while(q.empty()==false){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(auto v:g[u]){
            indegree[v]--;
            if(indegree[v]==0)
                q.push(v);
        }
    }
    return ans;
}
signed main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    vector<int> ans = topological_sorting(g);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}