#include<iostream>
#include<vector>
using namespace std;
class graph{
    public:
        int n;
        vector<int> *adj;
        int *parent;
        int *size;
        graph(int n);
        int find_set(int v);
        void find(int u, int v);
        void join(int u, int v);
};
graph::graph(int n){
    this->n = n;
    adj = new vector<int>[n];
    parent = new int[n];
    size = new int[n];
    for (int i = 0; i < n;i++){
        parent[i] = i;
        size[i] = 1;
    }
}
int graph::find_set(int v){
    if(v==parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void graph::find(int u,int v){
    bool flag=(find_set(u) == find_set(v));
    cout << flag << endl;
}
void graph::join(int u,int v){
    u = find_set(u);
    v = find_set(v);
    if(u!=v){
        if(size[u]>size[v])
            parent[v] = u, size[u] += size[v];
        else
            parent[u] = v, size[v] += size[u];
    }
}
int main(){
    int n,q;
    cin>>n>>q;
    graph g(n);
    for(int i=0,a,b,c;i<q;i++){
        cin>>a>>b>>c;
        if(a==0)
            g.join(b,c);
        else
            g.find(b,c);
    }
    return 0;
}