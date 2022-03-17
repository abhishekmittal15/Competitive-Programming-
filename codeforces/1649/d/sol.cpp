#include<iostream>
#include<vector>
using namespace std;

#define int long long int 

signed main(){

	int t;
	cin>>t;
	while(t--){

		int n,c;
		cin>>n>>c;
		vector<int> a(n);
		vector<int> freq(c+1,0);
		vector<int> cum_freq(c+1,0);
		for(int i=0;i<n;i++)
			cin>>a[i],freq[a[i]]++;
		for(int i=1;i<=c;i++)
			cum_freq[i]=cum_freq[i-1]+freq[i];
		bool ans=true;
		for(int x=1;x<=c;x++){
			if(freq[x]==0)
				continue;
			for(int y=x;y<=c;y+=x){
				int l=y;
				int r=min(y+x-1,c);
				/* cout<<x<<" "<<r<<endl; */
				if( cum_freq[r]>cum_freq[l-1] and freq[y/x]==0 ){
					ans=false;
					break;
				}
			}
			/* cout<<"-----------"<<endl; */
			if(ans==false)
				break;
		}
		string sans="No";
		if(ans)
			sans="Yes";
		cout<<sans<<endl;
	}
	return 0;
}

