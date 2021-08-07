#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int build(vector<int>& seg,vector<int>& a,int index,int start,int end){
    if(start==end)
        seg[index] = a[start];
    else{
        int mid = (start + end) / 2;
        seg[index] = build(seg, a, index * 2 + 1, start, mid) + build(seg, a, index * 2 + 2, mid + 1, end);
    }
    return seg[index];
}
int query(vector<int>& seg,vector<int>& a,int l,int r,int index,int pos){
    if(l==r)
        return seg[index];
    int mid = (l +r) / 2;
    if(pos<=mid)
        return seg[index] + query(seg, a, l, mid, index * 2 + 1, pos);
    return seg[index] + query(seg, a, mid + 1, r, index * 2 + 2, pos);
}
void update(vector<int>& seg,vector<int>& a,int index,int ql,int qr,int l,int r,int add){
    if(l>r)
        return;
    if(l==ql && r==qr)
        seg[index] += add;
    else{
        int mid = (l + r) / 2;
        update(seg,a,index * 2 + 1, l, mid, ql, min(r, mid), add);
        update(seg,a,index * 2 + 2, mid + 1, r, max(l, mid + 1), r, add);
    }
}
signed main(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    vector<int> seg(4*n);
    for (int i = 0; i < n;i++)
        cin >> a[i];
    build(seg, a, 0, 0, n - 1);
    for (int i = 0; i < q;i++){
        int query;
        cin >> query;
        int u, v,p;
        if(query==1){
            cin>>u>>v>>p;
            update(seg, a, 0, u, v, 0, n - 1, p);
        }
        else{
            cin >> u >> v;
            cout << query(seg, a, 0, n - 1, 0, u) + query(seg, a, 0, n - 1, 0, v) << endl;
        }
    }
    return 0;
}