#include<iostream>
#include<vector>
using namespace std;
#define int long long int 



signed main(){
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<q;i++){
		int query;
		cin>>query;
		if(query==0){
			int p,x;
			cin>>p>>x;
			update(p,x);
		}
		else{
			int l,r;
			cin>>l>>r;
			cout<<answer(l,r)<<endl;
		}
	}
	return 0;
}

