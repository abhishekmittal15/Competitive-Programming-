#include<iostream>
#include<vector>
using namespace std;

int solve(vector<vector<int>>& grid){

	int m = grid.size();
	int n = grid[0].size();
	const int inf = 1e9;
	vector<vector<int>> dp(m,vector<int>(n,0));
	dp[0][0]=grid[0][0];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(!(i==0 and j==0))
				dp[i][j]=min(i>0?dp[i-1][j]:inf,j>0?dp[i][j-1]:inf)+grid[i][j];
	return dp[m-1][n-1];

}

int main(){

	int m,n;
	cin>>m>>n;
	vector<vector<int>> grid(m,vector<int>(n,0));
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>grid[i][j];
	int ans = solve(grid);
	cout<<ans<<endl;
	return 0;

}
