#include<iostream>
#include<vector>
using namespace std;
#define int long long int 

int solve(vector<int>& a){

	int n=a.size();
	int max_sz=1e4+1;
	vector<int> freq(max_sz,0);
	vector<vector<int>> dp(max_sz,vector<int>(2,0));
	for(int i=0;i<n;i++){
		freq[a[i]]++;
	}
	for(int i=1;i<max_sz;i++){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		dp[i][1]=dp[i-1][0]+freq[i]*i;
	}
	return max(dp[max_sz-1][0],dp[max_sz-1][1]);
}

signed main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	int answer=solve(a);
	cout<<answer<<endl;
	return 0;
}
