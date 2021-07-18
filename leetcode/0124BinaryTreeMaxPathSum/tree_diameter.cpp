#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
void dfs(int u,int p,vector<vector<int>>& tree,vector<int>& f,vector<int>& g){
    int n = tree[u].size();
    cout << u<<" "<<n << endl;
    if(n==1){
        f[u]=1;
        g[u] = 0;
        return;
    }
    vector<int> temp;
    for (int i = 0; i < n;i++){
        if(tree[u][i]==p)
            continue;
        dfs(tree[u][i], u, tree, f, g);
        temp.push_back(f[tree[u][i]]);
    }
    sort(temp.begin(), temp.end());
    if (n == 2 && u!=0){
        f[u] = temp[0]+1;
        g[u] = f[u];
    }
    else{
        f[u] = temp[temp.size() - 1] + 1;
        g[u] = temp[temp.size() - 1] + temp[temp.size() - 2] + 1;
    }
}
int solve(vector<vector<int>>& tree){
    int n = tree.size();
    vector<int> f(n,0), g(n,0);
    dfs(0, -1, tree, f, g);
    for (int i = 0; i < n;i++){
        cout << i << " " << f[i] << " " << g[i] << endl;
    }
        return 0;
}
signed main(){
    int n;
    cin>>n;
    vector<vector<int>> tree(n);
    for (int i = 0; i < (n-1);i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int answer = solve(tree);
    cout << "Diameter is " << answer << endl;
    return 0;
}