#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

ll binpow(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b&1)
			ans=ans*a;
		a=a*a;
		b=b/2;
	}
	return ans;
}

ll solve(ll n){
	
	ll power=n/3;
	if(n%3==1)
		power--;
	ll answer=binpow(3,power)*2;
	if(n%3==1)
		answer*=2;
	return answer;

}

int main(){
	ll n;
	cin>>n;
	ll ans=solve(n);
	cout<<ans<<endl;
	return 0;
}
