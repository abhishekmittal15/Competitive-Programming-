#include<iostream>
#include<vector>
using namespace std;
#define int long long int 

int solve(int n){
	
	int mod=1e9+7;
	vector<int> dp(n+1,1);
	for(int i=1;i<=n;i++)
		dp[i]=((dp[i-1]*i)%mod*(2*i-1))%mod;
	return dp[n];

}

signed main(){

	int n;
	cin>>n;
	int answer=solve(n);
	cout<<answer<<endl;
	return 0;

}
