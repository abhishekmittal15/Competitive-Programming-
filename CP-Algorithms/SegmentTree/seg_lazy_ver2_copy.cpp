#include<iostream>
#include<vector>
typedef long long int ll;
using namespace std;
vector<ll> seg,a;
vector<bool> marked;

void push(ll v) {
    if (marked[v]) {
        seg[v*2] = seg[v*2+1] = seg[v];
        marked[v*2] = marked[v*2+1] = true;
        marked[v] = false;
    }
}

void update(int v, ll tl, ll tr, ll l, ll r, ll new_val) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        seg[v] = new_val;
        marked[v] = true;
    } else {
        push(v);
        ll tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), new_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
    }
}

ll get(ll v, ll tl, ll tr, ll pos) {
    if (tl == tr) {
        return seg[v];
    }
    push(v);
    ll tm = (tl + tr) / 2;
    if (pos <= tm) 
        return get(v*2, tl, tm, pos);
    else
        return get(v*2+1, tm+1, tr, pos);
}

int main(){
    ll n;
    cin>>n;
    a.clear();
    seg.clear();
    marked.clear();
    a.resize(n);
    seg.resize(4 * n);
    marked.resize(4 * n);
    for (ll i = 0; i < n;i++){
        cin >> a[i];
        update(0, 0, n - 1, i, i, a[i]);
    }
    for (ll i = 0; i < 10;i++)
        cout <<seg[i] << " ";
    cout << endl;
    return 0;
}