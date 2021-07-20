#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<vector<int>>& g,int k){
    
}
signed main(){
    int n,m,k;
    cin >> n >> m>>k;
    vector<vector<int>> g(n+1);
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    int answer = solve(g,k);
}