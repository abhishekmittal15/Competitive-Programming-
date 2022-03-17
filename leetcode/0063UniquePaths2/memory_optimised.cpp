#include<iostream>
#include<vector>
using namespace std;

#define int long long int 

int solve(vector<vector<int>>& grid){

	int m=grid.size();
	int n=grid[0].size();
	grid[0][0]=(grid[0][0]==1?0:1);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j]==1 and (i!=0 or j!=0)){
				grid[i][j]=0;
				continue;
			}
			if(i-1>=0)
				grid[i][j]=grid[i-1][j];
			if(j-1>=0)
				grid[i][j]+=grid[i][j-1];
		}
	}
	/* for(int i=0;i<m;i++){ */
	/* 	for(int j=0;j<n;j++) */
	/* 		cout<<grid[i][j]<<" "; */
	/* 	cout<<endl; */
	/* } */
	return grid[m-1][n-1];

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

