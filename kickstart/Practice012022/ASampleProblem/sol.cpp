#include<iostream>
#include<vector>
using namespace std;

#define int long long int 

signed main(){

	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int m,n;
		cin>>n>>m;
		int sum = 0;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			sum+=a;
		}
		int ans = sum%m;
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;

}

