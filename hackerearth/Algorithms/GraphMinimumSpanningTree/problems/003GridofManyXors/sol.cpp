#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int
struct pt{
    int x, y;
    pt(int x,int y){
        this->x = x;
        this->y = y;
    }
    friend bool operator==(const pt&a,const pt&b){
        return ((a.x == b.x) & (a.y == b.y));
    }
};
bool cmp(pair<int,pair<pt,pt>> &a,pair<int,pair<pt,pt>> &b){
    return (a.first <= b.first);
}
vector<vector<pt>> parent;
vector<vector<int>> sz;
pt f(pt u){
    if(parent[u.x][u.y]==u)
        return u;
    return parent[u.x][u.y] = f(parent[u.x][u.y]);
}
void un(pt u,pt v){
    u = f(u);
    v = f(v);
    if(sz[u.x][u.y]>sz[v.x][v.y])   
        swap(u,v);
    sz[v.x][v.y]+=sz[u.x][u.y];
    parent[u.x][u.y] = v;
}
vector<pair<int, pair<pt, pt>>> edges;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int r1,c1,r2,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        parent.clear();
        sz.clear();
        parent.resize(n,vector<pt>(m));
        sz.resize(n, vector<int>(m, 1));
        for (int i = 0; i < n;i++){
            for(int j=0;j<m;j++){
                parent[i][j] = pt(i, j);
            }
        }
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i <n; i++)
        {
            for (int j = 0;j<m;j++){
                cin >> mat[i][j];
                if(j>0)
                    edges.push_back({mat[i][j] ^ mat[i][j - 1], {pt(i, j), pt(i, j - 1)}});
                if(i>0)
                    edges.push_back({mat[i][j] ^ mat[i-1][j], {pt(i, j), pt(i-1, j)}});
                if(i<(n-1))
                    edges.push_back({mat[i][j] ^ mat[i+1][j], {pt(i, j), pt(i+1, j)}});
                if(j<(m-1))
                    edges.push_back({mat[i][j] ^ mat[i][j + 1], {pt(i, j), pt(i, j + 1)}});
            }
        }
        sort(edges.begin(), edges.end(),cmp);
        int cnt_edges = 0, cost = 0;
        for(auto edge:edges){
            int w=edge.first;
            pt u = edge.second.first;
            pt v = edge.second.second;
            if(f(u)==f(v))
                continue;
            cost+=w;
            cnt_edges++;
            un(u, v);
            if(cnt_edges==(m*n-1))
                break;
        }
        cout << cost << endl;
    }
    return 0;
}