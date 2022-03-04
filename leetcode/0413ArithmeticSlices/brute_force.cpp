#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

ll solve(vector<ll> &a){

	ll cnt=0;
	ll n=a.size();
	for(ll start=0;start<n-3;start++){
		int diff1=(a[start+2]-a[start+1]);
		int diff2=(a[start+1]-a[start]);
		bool flag=diff1==diff2;
		cnt+=(flag?1:0);
		if(flag==false)
			break;
		for(ll end=start+3;end<n;end++){
			int diff=a[end]-a[start];
			if(diff!=diff1)
				break;
			cnt++;
		}
	}
	return cnt;

}

int main(){
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll answer=solve(a);
	cout<<answer<<endl;
	return 0;
}
