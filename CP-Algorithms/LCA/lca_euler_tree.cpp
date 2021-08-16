#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
vector<vector<int>> tree;
vector<int> euler;
vector<int> heights;
vector<int> tin;
vector<int> seg;
int inf = 1e9 + 7;
int timer = 0;
void update(int l,int r,int index,int pos){
    cout << l << " " << r << " " << index << " " << pos << endl;
    if(l==r){
        seg[index] = euler[l];
        return;
    }
    int mid = (l + r) / 2;
    if(pos<=mid)
        update(l, mid, index * 2 + 1, pos);
    else
        update(mid+1,r,index*2+2,pos);
    int left = seg[index * 2 + 1];
    int right = seg[index * 2 + 2];
    seg[index] = (heights[left] < heights[right]) ? left : right;
}
int query(int l,int r,int index,int ql,int qr){
    if (l > qr || r < ql)
        return -1;
    if (l >= ql && r <= qr)
        return seg[index];
    int mid = (l + r) / 2;
    int query1 = query(l, mid, index * 2 + 1, ql, qr);
    int query2 = query(mid + 1, r, index * 2 + 2, ql, qr);
    if(query1==-1)
        return query2;
    if (query2 == -1)
        return query1;
    return (heights[query1] < heights[query2]) ? query1 : query2;
}
void dfs(int u,int p,int h){
    tin[u] = timer;
    timer++;
    euler.push_back(u);
    heights[u] = h;
    for(auto v:tree[u]){
        if(v==p)
            continue;
        dfs(v, u,h+1);
        euler.push_back(u);
        timer++;
    }
}
signed main(){
    int n;
    cin >> n;
    tree.resize(n + 1);
    tin.resize(n + 1);
    heights.resize(n + 1);
    heights[0] = inf;
    for (int i = 1;i<n;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0,1);
    int sz = euler.size() - 1;
    seg.resize(sz * 4,0);
    for (int i = 0; i < sz;i++)
        update(0,sz-1,0,i);
    int q;
    cin >> q;
    while(q--){
        int u,v;
        cin >> u >> v;
        if(tin[u]>tin[v])
            swap(u,v);
        cout << query(0, sz-1, 0, tin[u], tin[v]) << endl;
    }
    return 0;
}