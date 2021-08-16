struct segtree{
    vector<int> seg;
    int sz;
    int inf = 1e9 + 7;
    segtree(int n){
        sz =4* n;
        seg.resize(4 * n,inf);
    }
    void update(int l,int r,int index,int pos,int val){
        if(l>pos || pos>r)
            return;
        if(l==pos && r==pos){
            seg[index]=val;
            return;
        }
        int mid = (l + r) / 2;
        update(l, mid, index * 2 + 1, pos, val);
        update(mid + 1, r, index * 2 + 2, pos, val);
        seg[index] = min(seg[index * 2 + 1], seg[index * 2 + 2]);
    }
    int query(int l,int r,int index,int ql,int qr){
        if(ql>qr)
            return inf;
        if(ql==l && qr==r)
            return seg[index];
        int mid = (l + r) / 2;
        int query1 = query(l, mid, index * 2 + 1, ql, min(mid,qr));
        int query2 = query(mid + 1, r, index * 2 + 2, max(ql, mid + 1), qr);
        return min(query1, query2);
    }
};