#include<iostream>
#include<vector>
using namespace std;
typedef long long int ll;
vector<ll> seg, a;
vector<bool> marked;
void push(int v){
    if(marked[v]){
        seg[v * 2 + 1] = seg[v];
        seg[v * 2 + 2] = seg[v];
        marked[v*2+1]=true;
        marked[v*2+2]=true;
        marked[v] = false;
    }
}
void update(ll l, ll r, ll pos1, ll pos2, ll index, ll val)
{
    cout << l << " " << r << " " << " "<<pos1<<" "<<pos2<<" "<<index << " " << val << endl;
    if(pos1>pos2)
        return ;
    if(l==pos1 && r==pos2){
        seg[index]=val;
        marked[index] = true;
    }
    else{
        push(index);
        ll mid = (l + r) / 2;
        update(l, mid, pos1, min(pos2,mid),index * 2 + 1,val);
        update(mid+1, r, max(pos1,mid+1), pos2, index * 2 + 2,val);
    }
}
int query(ll l,ll r,ll index,ll pos){
    if(l==r)
        return seg[index];
    push(index);
    int mid = (l + r) / 2;
    if(pos<=mid)
        return query(l, mid, index * 2 + 1, pos);
    return query(mid + 1, r, index * 2 + 2, pos);
}
int main(){
    ll n;
    cin>>n;
    a.clear();
    seg.clear();
    marked.clear();
    a.resize(n);
    marked.resize(4*n, false);
    seg.resize(4 * n,0);
    for (ll i = 0; i < n;i++){
        cin >> a[i];
        update(0, n - 1, i, i, 0,a[i]);
    }
    for (ll i = 0; i < 10;i++)
        cout << seg[i]<<" ";
    cout << endl;
    return 0;
}