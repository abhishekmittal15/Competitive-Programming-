#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n+1);
    vector<int> cnt(n + 1,0);
    for (int i = 0; i < (n-1);i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        cnt[u]++;
        cnt[v]++;
    }
    
}