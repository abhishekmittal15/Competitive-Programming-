#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long int 

class dsu{

	private:
		vector<int> parent,sz;
		int max_sz;

	public:
		dsu(int n){
			max_sz=n;
			parent.resize(max_sz);
			sz.resize(max_sz,1);
			for(int i=0;i<max_sz;i++)
				parent[i]=i;
		}
	
		int fnd(int i){
			if(i==parent[i])
				return i;
			return parent[i]=fnd(parent[i]);
		}

		void un(int i,int j){
			i=fnd(i);
			j=fnd(j);
			if(sz[i]>sz[j])
				swap(i,j);
			parent[i]=j;
			sz[j]+=sz[i];
		}
		
		void print(int n){
			for(int i=0;i<n;i++){
				cout<<i<<" "<<parent[i]<<" "<<sz[i]<<endl;
			}
		}

};

bool solve(vector<int>& a){
	
	bool ans=true;
	int n=a.size();
	int max_num=1e5+5;
	vector<bool> exists(max_num,false);
	for(int i=0;i<n;i++)
		exists[a[i]]=true;
	vector<bool> is_prime(max_num,true);
	dsu ds(max_num);
	for(int i=2;i<max_num;i++){
		if(is_prime[i]==false)
			continue;
		for(int j=2*i;j<max_num;j+=i){
			is_prime[j]=false;
			if(exists[j] and ds.fnd(i)!=ds.fnd(j))
				ds.un(i,j);
		}
	}
	vector<int> sort_arr(a);
	sort(sort_arr.begin(),sort_arr.end());
	for(int i=0;i<a.size();i++){
		if(ds.fnd(a[i])!=ds.fnd(sort_arr[i])){
			ans=false;
			break;
		}
	}
	return ans;
}	

signed main(){

	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	bool answer=solve(a);
	cout<<answer<<endl;
	return 0;

}
