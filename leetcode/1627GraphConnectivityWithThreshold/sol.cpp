#include<iostream>
#include<vector>
using namespace std;

#define int long long int 

int fnd(int v,vector<int>& parent){
	if(v==parent[v])
		return v;
	return parent[v]=fnd(parent[v],parent);
}

void un(int u,int v,vector<int>& parent,vector<int>& sz){
	if(sz[u]>sz[v])
		parent[v]=u,sz[u]+=sz[v];
	else
		parent[u]=v,sz[v]+=sz[u];
}

vector<bool> solve(int n,int threshold,vector<vector<int>>& queries){

	int q=queries.size();
	vector<bool> answers(q);
	vector<int> parent(n+1);
	vector<int> sz(n+1);
	for(int i=1;i<=n;i++)
		parent[i]=i,sz[i]=1;
	for(int i=threshold+1;2*i<=n;i++){
		for(int j=2*i;j<=n;j+=i){
			int p1=fnd(i,parent);
			int p2=fnd(j,parent);
			if(p1==p2)
				continue;
			un(p1,p2,parent,sz);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<i<<" "<<parent[i]<<endl;
	}
	for(int i=0;i<q;i++)
		answers[i]=fnd(queries[i][0],parent)==fnd(queries[i][1],parent);
	return answers;

}

signed main(){
	
	int n,q,threshold;
	cin>>n>>q>>threshold;
	vector<vector<int>> queries(q,vector<int>(2,0));
	for(int i=0;i<q;i++)
		cin>>queries[i][0]>>queries[i][1];
	vector<bool> answers=solve(n,threshold,queries);
	for(int i=0;i<q;i++){
		cout<<queries[i][0]<<" "<<queries[i][1]<<" "<<answers[i]<<endl;
	}
	return 0;
}
