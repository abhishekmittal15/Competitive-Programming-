#include<iostream>
#include<vector>
using namespace std;
#define int long long int 

class dsu{

	private:
		int* parent;
		int* sz;
		int n;
	public:
		dsu(int max_sz){
			n=max_sz;
			parent=new int[max_sz];
			sz=new int[max_sz];
			for(int i=0;i<max_sz;i++)
				parent[i]=i,sz[i]=1;
		}
		int fnd(int u){
			if(u==parent[u])
				return u;
			return parent[u]=fnd(parent[u]);
		}

		void un(int u,int v){
			u=fnd(u);
			v=fnd(v);
			if(u==v)
				return;
			if(sz[u]>sz[v])
				swap(u,v);
			parent[u]=v;
			sz[v]+=sz[u];
		}
	
		void print(){
			for(int i=0;i<n;i++){
				cout<<i<<" "<<parent[i]<<" "<<sz[i]<<endl;
			}
		}

};

vector<bool> solve(int n,int threshold,vector<vector<int>>& queries){

	int q=queries.size();
	dsu ds(n+1);
	vector<bool> answer(q);
	for(int i=threshold+1;2*i<=n;i++){
		for(int j=2*i;j<=n;j+=i){
			if(ds.fnd(i)==ds.fnd(j))
				continue;
			ds.un(i,j);
		}
	}
	/* ds.print(); */
	for(int i=0;i<q;i++)
		answer[i]=ds.fnd(queries[i][0])==ds.fnd(queries[i][1]);

	return answer;

}

signed main(){

	int n,q,threshold;
	cin>>n>>q>>threshold;
	vector<vector<int>> queries(q,vector<int>(2,0));
	for(int i=0;i<q;i++)
		cin>>queries[i][0]>>queries[i][1];
	vector<bool> answer=solve(n,threshold,queries);
	for(int i=0;i<q;i++){
		cout<<queries[i][0]<<" "<<queries[i][1]<<" "<<answer[i]<<endl;
	}
	return 0;

}
