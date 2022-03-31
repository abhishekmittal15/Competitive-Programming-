#include<iostream>
#include<vector>
using namespace std;

int solve(const vector<int>& a){

	int n = a.size();
	// iterate over the elements of a 
	// at the ith index, find the max_len, dp[i] and cnt[i] 
	// LIS_len = length of LIS
	// final answer is sum of all the cnt[i] such that dp[i] == LIS_len
	vector<int> dp(n,0);
	vector<int> cnt(n,0);
	for(int i=0;i<n;i++){
		int max_len = 0;
		for(int j=0;j<i;j++){
			if(a[i]>a[j]){
				// case 1: new max_len found
				// update the cnt[i]=0 and dp[i]=0
				// case 2: we find the same max_len again 
				// increment cnt[i] by cnt[j] and dp[i]=dp[j]
				if(dp[i] < dp[j]){
					cnt[i]=0;
					dp[i] = dp[j];
				}
				if(dp[i] == dp[j]){
					cnt[i]+=cnt[j];
				}	
			}
		}
		dp[i]++;
		cnt[i]=max(1,cnt[i]); // incase we get no such a[j]<a[i], then treat the current element as a potential subsequence of length 1 
	}
	
	/* for(int i = 0;i < n ; i++) */
	/* 	cout<<i<<" "<<dp[i]<<" "<<cnt[i]<<endl; */

	int LIS_len = 0;
	int ans = 0;
	for(auto i: dp)
		LIS_len = max(LIS_len,i);
	for(int i = 0; i < n ; i++ )
		if(dp[i]==LIS_len)
			ans += cnt[i];
	return ans;

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
