#include<iostream>
#include<vector>
using namespace std;

#define PACIFIC 1
#define ATLANTIC 2

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void dfs(int x, int y,const vector<vector<int>>& grid, vector<vector<bool>>& reachability){

	/* cout<<x<<" "<<y<<endl; */
	int m = grid.size();
	int n = grid[0].size();
	reachability[x][y] = true;
	for(int k = 0;k<4;k++){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(nx<0 or nx>=m or ny<0 or ny>=n or grid[nx][ny]<grid[x][y] or reachability[nx][ny]==true)
			continue;
		dfs(nx,ny,grid,reachability);
	}

}

vector<vector<int>> solve(const vector<vector<int>>& grid){

	int m = grid.size();
	int n = grid[0].size();
	vector<vector<bool>> atlantic(m,vector<bool>(n,false));
	vector<vector<bool>> pacific(m,vector<bool>(n,false));
	vector<vector<int>> ans;
	for(int i = 0;i<m;i++)
		dfs(i,0,grid,pacific);
	for(int i = 0;i<n;i++)
		dfs(0,i,grid,pacific);
	for(int i = 0;i<m;i++)
		dfs(i,n-1,grid,atlantic);
	for(int i = 0;i<n;i++)
		dfs(m-1,i,grid,atlantic);
	for(int i = 0;i<m;i++)
		for(int j = 0;j<n;j++)
			if(pacific[i][j] and atlantic[i][j])
				ans.push_back({i,j});
	return ans;

}

int main(){

	int m,n;
	cin>>m>>n;
	vector<vector<int>> grid(m,vector<int>(n,0));
	for(int i = 0;i < m;i++)
		for(int j = 0;j < n;j++)
			cin>>grid[i][j];
	vector<vector<int>> ans = solve(grid);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
	return 0;

}
