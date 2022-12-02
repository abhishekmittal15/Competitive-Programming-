#include<iostream>
#include<vector>
using namespace std;

int f(int idx, int absents, int trailing_leaves, int n,vector<vector<vector<int>>>& dp){

	/* cout << idx << " " << absents << " " << trailing_leaves << endl; */
	const int mod = 1e9 + 7;
	int ways = 0;
	if(idx >= n)
		return 1;
	if(dp[idx][absents][trailing_leaves] != -1)
		return dp[idx][absents][trailing_leaves];;
	if(absents>0)
		ways += f(idx+1, absents-1, 0,n,dp);
	ways %= mod;
	if(trailing_leaves<2)
		ways += f(idx+1, absents, trailing_leaves+1,n,dp);
	ways %= mod;
	ways += f(idx+1,absents,0,n,dp);
	ways %= mod;
	return dp[idx][absents][trailing_leaves] = ways;

}

int solve(int n){

	vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
	int idx = 0;
	int absents = 1;
	int trailing_leaves = 0;
	int ans = f(idx,absents,trailing_leaves,n,dp);
	return ans;

}

int main(){

	int n;
	cin >> n;
	int ans = solve(n);
	cout << ans << endl;
	return 0;
	
}
