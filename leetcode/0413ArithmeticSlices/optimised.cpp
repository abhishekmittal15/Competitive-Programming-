#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

ll solve(vector<ll>& a){

	ll n=a.size();
	if(n==1 or n==2)
		return 0;
	ll cnt=2;
	ll diff=0;
	ll answer=0;
	for(int i=2;i<n;i++){
		
		if(cnt==2){
			diff=a[i]-a[i-1];
			if(diff==(a[i-1]-a[i-2]))
				cnt=3;
		}
		else{
			if(a[i]-a[i-1]==diff)
				cnt++;
			else{
				answer+=(((cnt-1)*(cnt-2))/2);
				cnt=2;
			}
		}
		
	}
	answer+=(((cnt-1)*(cnt-2))/2);
	return answer;
}


int main(){
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(ll i=0;i<n;i++)
		cin>>a[i];
	ll answer=solve(a);
	cout<<answer<<endl;
	return 0;
}
