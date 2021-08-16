#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
vector<vector<int>> tree;
vector<int> euler;
vector<int> tin;
int timer = 0;
void dfs(int u,int p){
    euler.push_back(u);
    tin[u] = timer;
    timer++;
    for(auto v:tree[u]){
        if(p==v)
            continue;
        dfs(v, u);
        euler.push_back(u);
        timer++;
    }
}
signed main(){
    int n;
    cin>>n;
    tree.resize(n + 1);
    tin.resize(n + 1);
    for (int i = 1; i < n;i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 0; i < euler.size();i++){
        cout << euler[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n;i++)
        cout << i << " " << tin[i] << endl;
    cout << endl;
    return 0;
}