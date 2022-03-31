#include<iostream>
#include<vector>
using namespace std;

int solve(vector<vector<int>>& grid){

	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> dp(n,vector<int>(2,0));
	dp[0][0]=grid[0][0];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int cur_row = (i+1)%2;
			int prev_row = i%2;
			dp[cur_row][j] = dp[prev_row][j];
			if(j>0)
				dp[cur_row][j] = min(dp[cur_row][j],dp[cur_row][j-1]);
			dp[cur_row][j] += grid[i][j];
		}
	}
	return dp[m%2][n-1];

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
