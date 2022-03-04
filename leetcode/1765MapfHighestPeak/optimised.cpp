#include<iostream>
#include<vector>
#include<climits>
using namespace std;

#define int long long int 

vector<vector<int>> solve(vector<vector<int>>& grid){

	int m=grid.size();
	int n=grid[0].size();
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			grid[i][j]=(grid[i][j]==1?0:INT_MAX-n*m);
		}
	}

	// Left to Right sweep
	for(int i=0;i<m;i++){
		int prev=0;
		for(int j=0;j<n;j++){
			if(j!=0)
				grid[i][j]=min(prev+1,grid[i][j]);
			prev=grid[i][j];
		}
	}

	// Right to Left Sweep 
	for(int i=0;i<m;i++){
		int prev=0;
		for(int j=n-1;j>=0;j--){
			if(j!=n-1)
				grid[i][j]=min(prev+1,grid[i][j]);
			prev=grid[i][j];
		}
	}

	// Up Down Sweep 
	for(int i=0;i<n;i++){
		int prev=0;
		for(int j=0;j<m;j++){
			if(j!=0)
				grid[j][i]=min(prev+1,grid[j][i]);
			prev=grid[j][i];
		}
	}
	
	// Down Up Sweep 
	for(int i=0;i<n;i++){
		int prev=0;
		for(int j=m-1;j>=0;j--){
			if(j!=m-1)
				grid[j][i]=min(prev+1,grid[j][i]);
			prev=grid[j][i];
		}
	}

	return grid;
}

signed main(){
	
	int m,n;
	cin>>m>>n;
	vector<vector<int>> grid(m,vector<int>(n,0));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>grid[i][j];
		}
	}
	vector<vector<int>> heights=solve(grid);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<heights[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
