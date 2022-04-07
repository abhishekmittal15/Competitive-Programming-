#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

string bfs(vector<vector<string>>& grid,int si,int sj,int ti,int tj){

	int n = grid.size();
	queue<pair<int,int>> q;
	// My parent grid will be useful in finding the shortest path and it can also serve as a good substitute for a separate visited array. If not visited then parent of that cell will be {-1,-1}
	pair<int,int> init_parent = {-1,-1};
	vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(n,init_parent));
	q.push({si,sj});
	// parent of the initial cell needs to be set to itself and will serve as a terminating condition while finding the path. 
	parent[si][sj] = {si,sj};
	string ans = "";
	while(!q.empty()){
		pair<int,int> curr = q.front();
		int x = curr.first;
		int y = curr.second;
		/* cout << x << " " << y << endl; */
		if(x == ti and y == tj)
			break;
		q.pop();
		string dir = grid[x][y];
		for(int i = 0; i < dir.size(); i++){
			int nx = x, ny = y;
			switch(dir[i]){
				case 'U':
					nx--;
					break;
				case 'D':
					nx++;
					break;
				case 'R':
					ny++;
					break;
				case 'L':
					ny--;
					break;
			}
			if(parent[nx][ny]!=init_parent)
				continue;
			parent[nx][ny] = curr;
			q.push({nx,ny});
		}
	}

	int x = ti, y = tj;
	map<pair<int,int>,char> directions;
	directions[pair<int,int>(-1,0)]='U';
	directions[pair<int,int>(1,0)]='D';
	directions[pair<int,int>(0,-1)]='L';
	directions[pair<int,int>(0,1)]='R';

	while(parent[x][y]!=pair<int,int>(x,y)){
		int prev_x = parent[x][y].first;
		int prev_y = parent[x][y].second;
		pair<int,int> diff(x-prev_x,y-prev_y);
		ans+=(directions[diff]);
		x = prev_x;
		y = prev_y;
	}
	reverse(ans.begin(),ans.end());
	return ans;
	
}

int main(){

	int si,sj,ti,tj;
	double p;
	cin>>si>>sj>>ti>>tj;
	cin>>p;
	int n = 20;
	// Each cell has the directions we can go from it as string ULDR
	vector<vector<string>> grid(n,vector<string>(n,""));
	vector<string> h(n);
	vector<string> v(n-1);

	// Take the horizontal row walls as input
	for(int i = 0; i < n; i++){
			cin >> h[i];
	}

	// Take the vertical column walls as input 
	for(int i = 0; i < n - 1; i++){
			cin >> v[i];
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			// if i > 0 and v[i-1][j] is false then add U
			if( i > 0 and v[i-1][j] == '0')
				grid[i][j]+="U";
			// if i < n-1 and v[i][j] is false then add D
			if( i < n-1 and v[i][j] == '0')
				grid[i][j]+="D";
			// if j > 0 and h[i-1][j] is false then add L
			if( j > 0 and h[i][j-1] == '0')
				grid[i][j]+="L";
			// if j < n-1 and h[i][j] is false then add R
			if( j < n-1 and h[i][j] == '0')
				grid[i][j]+="R";
			/* cout << i << " " << j << " " << grid[i][j] << endl; */
		}
	}

	string ans = bfs(grid,si,sj,ti,tj);
	cout << ans << endl;
	return 0;

}

