#include<iostream>
#include<vector>
using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

pair<int,int> check(vector<vector<int>>& grid){

	int num_visited=0;
	int obstacles=0;
	int m=grid.size();
	int n=grid[0].size();
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j]==3)
				num_visited++;
			else if(grid[i][j]==-1)
				obstacles++;
		}
	}
	return {num_visited,obstacles};

}

void f(int i,int j,vector<vector<int>>& grid,int &answer){

	int m=grid.size();
	int n=grid[0].size();
	if(grid[i][j]==2){
		pair<int,int> params=check(grid);
		int	num_visited=params.first;
		int obstacles=params.second;
		if(m*n-obstacles==num_visited+1)
			answer++;
		return;
	}
	grid[i][j]=3;
	for(int k=0;k<4;k++){
			
		int nextx=i+dx[k];
		int nexty=j+dy[k];
		if(nextx<0 or nextx>=m or nexty<0 or nexty>=n or grid[nextx][nexty]==3 or grid[nextx][nexty]==-1)
			continue;
		f(nextx,nexty,grid,answer);	

	}
	grid[i][j]=0;

}

int solve(vector<vector<int>>& grid){

	int m=grid.size();
	int n=grid[0].size();
	int answer=0;
	int startx=0,starty=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(grid[i][j]==1)
				startx=i,starty=j;
	f(startx,starty,grid,answer);
	return answer;

}

int main(){

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
