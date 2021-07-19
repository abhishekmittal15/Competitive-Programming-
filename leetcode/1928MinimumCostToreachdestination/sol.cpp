#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define int long long int 
int solve(int maxTime,vector<vector<int>>& edges,vector<int>& passingFees){
    int n = passingFees.size();
    int inf = 1000 * 1000 * 1000 + 7;
    vector<int> distance(n, inf);
    distance[0] = 0;

    // Construct a graph from the edges list

    vector<vector<pair<int,int>>> tree(n);
    for (int i = 0; i < edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int time = edges[i][2];
        adj[u].push_back({v, time});
        adj[v].push_back({u, time});
    }

    priority_queue<
}
signed main(){
    int n,m,maxTime;
    cin >>n>> m>>maxTime;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m;i++){
        int u, v, time;
        cin >> u >> v >> time;
        adj[u].push_back({v, time});
        adj[v].push_back({u, time});
    }
    vector<int> passingFees(n);
    for (int i = 0; i < n;i++)
        cin >> passingFees[i];
    int answer = solve(maxTime, edges, passingFees);
    cout << "Answer : " << answer << endl;
    return 0;
}
