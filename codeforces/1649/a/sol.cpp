#include<iostream>
using namespace std;
#define int long long int 

signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		int ans=0;
		cin>>n;
		int first=n+1,last=-1;
		for(int i=0;i<n;i++){
			
			int a;
			cin>>a;
			if(a==0)
				first=min(first,i),last=max(last,i);

		}
		if(first<=last)
			ans=last-first+2;
		cout<<ans<<endl;
	}
	return 0;
}
			
