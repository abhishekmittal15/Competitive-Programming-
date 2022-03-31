#include<iostream>
#include<vector>
using namespace std;

int solve(const vector<int>& a){

	int n = a.size();
	// dp[i] represents the LIS till the ith index 
	vector<int> dp(n,0);
	// our LIS might end at any ith index, so ans takes the maximum value of all the indices
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[j]<a[i])
				dp[i]=max(dp[i],dp[j]);
		}
		dp[i]++;
	}
	return dp[n-1];

}

int main(){

	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &i: a)
		cin>>i;
	int ans = solve(a);
	cout<<ans<<endl;
	return 0;

}
