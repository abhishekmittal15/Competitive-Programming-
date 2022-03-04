#include<iostream>
#include<vector>
using namespace std;
#define int long long int 

vector<int> parent;
vector<int> sz;

int fnd(int u){
    if(u==parent[u])
        return u;
    return parent[u]=fnd(parent[u]);
}

bool in_same(int u,int v){
    return fnd(u)==fnd(v);
}

void add_edge(int u,int v){
    
    int pv=fnd(v);
    int pu=fnd(u);
    if(pu==pv)
        return;
    if(sz[pu]<sz[pv])
        sz[pv]+=sz[pu],parent[pu]=pv;
    else
        sz[pu]+=sz[pv],parent[pv]=pu;
    return;

}

void preprocess(){
    for(int i=0;i<(int)(sz.size());i++)
        sz[i]=1,parent[i]=i;
}

signed main(){

    int n,q;
    cin>>n>>q;
    parent.resize(n);
    sz.resize(n);
    preprocess();
    for(int i=0;i<q;i++){
        int query;
        int u,v;
        cin>>query;
        cin>>u>>v;
        if(query==0){
            add_edge(u,v);
        }
        else{
            bool answer=in_same(u,v);
            cout<<answer<<endl;
        }
    }
    return 0;
}
