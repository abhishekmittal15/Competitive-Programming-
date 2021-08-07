#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
ll n;
ll dx[4] = { -1, 0, 0, 1 };
ll dy[4] = { 0, 1, -1, 0 };
vector<vector<bool>> visited;
vector<vector<pair<ll,ll>>> parent;
vector<vector<ll>> sz;
ll dfs(ll x,ll y,ll px,ll py){
    ll cnt = 1;
    visited[x][y] = true;
    parent[x][y] = {px, py};
    for (ll i = 0; i < 4;i++){
        ll nextx = x + dx[i];
        ll nexty = y + dy[i];
        if(nextx<0 || nextx>=n || nexty<0 || nexty>=n || visited[nextx][nexty]==true)
            continue;
        cnt += dfs(nextx, nexty,px,py);
    }
    return cnt;
}
ll solve(vector<vector<ll>>& grid){
    ll ans = 0;
    n = grid.size();
    visited.resize(n);
    parent.resize(n);
    sz.resize(n);
    for (ll i = 0; i < n; ++i){
        visited[i].resize(n,false);
        parent[i].resize(n,{1ll*0,1ll*0});
        sz[i].resize(n,1ll*0);
    }
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            visited[i][j] = 1 - grid[i][j];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
            if (visited[i][j] == false && grid[i][j] == 1)
                sz[i][j] = dfs(i, j, i, j);
    }
    for (ll i = 0; i < n;i++)
        for (ll j = 0; j < n;j++){
            // cout <<i<<" "<<j<<" "<< sz[i][j] << endl;
            ans = max(ans, sz[i][j]);
        }
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            if (grid[i][j] == 0)
            {
                ll cnt = 1;
                set<pair<ll, ll>> vis;
                for (ll k = 0; k < 4; k++)
                {
                    ll nextx = i + dx[k];
                    ll nexty = j + dy[k];
                    if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= n)
                        continue;
                    if(grid[nextx][nexty]==1){
                        ll cur_px = parent[nextx][nexty].first;
                        ll cur_py = parent[nextx][nexty].second;
                        ll cur_size = vis.size();
                        vis.insert(parent[nextx][nexty]);
                        if(vis.size()>cur_size)
                        cnt += sz[cur_px][cur_py];
                    }
                }
                ans = max(ans, cnt);
            }
    return ans;
}
int main(){
    ll n;
    cin>>n;
    vector<vector<ll>> grid(n,vector<ll>(n));
    for (ll i = 0; i < n;i++)
        for (ll j = 0; j < n;j++)
            cin >> grid[i][j];
    ll ans = solve(grid);
    cout << "Answer : " << ans << endl;
    return 0;
}