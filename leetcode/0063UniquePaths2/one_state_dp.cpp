#include<iostream>
#include<vector>
using namespace std;

#define int long long int 

int solve(vector<vector<int>>& grid){

	int m=grid.size();
	int n=grid[0].size();
	vector<vector<int>> dp(n,vector<int>(2,0));
	dp[0][0]=grid[0][0]==1?0:1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j]==1)
				continue;
			if(i-1>=0)
				dp[j][i%2]=dp[j][(i+1)%2];
			if(j-1>=0)
				dp[j][i%2]+=dp[j-1][i%2];
		}
	}
	return dp[n-1][(m-1)%2];

}

signed main(){

	int m,n;
	cin>>m>>n;
	vector<vector<int>> grid(m,vector<int>(n,0));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			cin>>grid[i][j];
	}
	int answer=solve(grid);
	cout<<answer<<endl;
	return 0;

}

