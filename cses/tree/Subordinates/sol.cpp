#include<iostream>
#include<vector>
using namespace std;
#define int long long int
void dfs(int u,vector<vector<int>>& tree,vector<int>& sz)
{
    sz[u] = 1;
    for (auto it : tree[u])
    {
        dfs(it,tree,sz);
        sz[u] += sz[it];
    }
    return;
}
signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    vector<int> sz(n + 1);
    for (int i = 2, boss; i <= n; i++)
    {
        cin >> boss;
        tree[boss].push_back(i);
    }
    dfs(1,tree,sz);
    for (int i = 1; i <= n; i++)
    {
        cout << sz[i] - 1 << " ";
    }
    cout << endl;
    return 0;
}
