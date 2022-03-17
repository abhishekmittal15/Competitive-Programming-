#include<iostream>
using namespace std;

#define int long long int 

int solve(int n){
	
	int mod=1e9+7;
	int answer=1;
	for(int i=1;i<=n;i++)
		answer=((answer*i)%mod*(2*i-1))%mod;
	return answer;

}

signed main(){

	int n;
	cin>>n;
	int answer=solve(n);
	cout<<answer<<endl;
	return 0;

}
