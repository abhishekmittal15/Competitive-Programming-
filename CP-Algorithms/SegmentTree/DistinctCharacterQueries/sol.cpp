#include<iostream>
#include<vector>
using namespace std;
#define int long long int
string s;
int build(int index,int start,int end,vector<int>& seg){
    if(start==end){
        seg[index] = 1<<(s[start]-'a');
    }
    else{
        int mid = (start + end) / 2;
        seg[index] = build(index * 2 + 1, start, mid, seg) | build(index * 2 + 2, mid + 1, end, seg);
    }
    return seg[index];
}
// void update(int start,int end,int index,vector<int>& seg,int pos,char ch){
//     if(start==end)
//         seg[index] = 1 << (ch - 'a');
//     else{

//     }
//     return seg[index];
// }
int query(int index,int start,int end,int qs,int qe,vector<int>& seg){
    if(qs>end || qe<start)
        return 0;
    if(qs==start && qe==end)
        return seg[index];
    int mid = (start + end) / 2;
    return query(index * 2 + 1, start, mid, qs, qe, seg) | query(index * 2 + 2, mid + 1, end, qs, qe, seg);
}
signed main(){
    cin >> s;
    int q;
    cin >> q;
    int n = s.length();
    vector<int> seg(4 * n);
    build(0,0,n-1,seg);
    while(q--){
        int a, b, c;
        cin>>a>>b>>c;
        if(a==1){
            
        }
        else{
            cout << __builtin_popcountll(query(0, 0, n - 1, b, c, seg));
        }
    }
    return 0;
}