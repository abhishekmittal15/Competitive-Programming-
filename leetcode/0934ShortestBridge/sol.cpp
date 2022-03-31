#include<iostream>
#include<queue>
using namespace std;

#define int long long int 

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void print(vector<vector<int>>& grid){

	int m=grid.size();
	int n=grid[0].size();
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			cout<<grid[i][j]<<" ";
		cout<<endl;
	}
	
}

int solve(vector<vector<int>>& grid){

	int n=grid.size();
	int answer=0;
	queue<pair<int,int>> bfs1;
	queue<pair<int,int>> bfs2;
	bool found=false;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j]==1){
				grid[i][j]=2;
				bfs1.push({i,j});
				found=true;
				break;
			}
		}
		if(found)
			break;
	}			
	while(!bfs1.empty()){
	
		pair<int,int> loc=bfs1.front();
		bfs1.pop();
		int x=loc.first;
		int y=loc.second;
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0 or nx>=n or ny<0 or ny>=n or grid[nx][ny]==2)
				continue;
			if(grid[nx][ny]==1)
				bfs1.push({nx,ny});
			if(grid[nx][ny]==0)
				bfs2.push({nx,ny});
			grid[nx][ny]=2;
		}
		
	}
	print(grid);
	while(!bfs2.empty()){
	
		int sz=bfs2.size();
		while(sz--){
			pair<int,int> loc=bfs2.front();
			bfs2.pop();
			int x=loc.first;
			int y=loc.second;
			for(int i=0;i<4;i++){
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(nx<0 or nx>=n or ny<0 or ny>=n or grid[nx][ny]==2)
					continue;
				if(grid[nx][ny]==1)
					return answer+1;
				grid[nx][ny]=2;
				bfs2.push({nx,ny});
			}
		}
		answer++;
		
	}
	print(grid);	
	return answer;
}

signed main(){

	int n;
	cin>>n;
	vector<vector<int>> grid(n,vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>grid[i][j];
		}
	}
	int answer=solve(grid);
	cout<<answer<<endl;
	return 0;

}
