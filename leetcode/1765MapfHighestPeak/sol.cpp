#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;
ll dx[4]={1,-1,0,0};
ll dy[4]={0,0,1,-1};
vector<vector<ll>> solve(vector<vector<ll>>& grid){

	queue<pair<ll,ll>> q;
	ll m=grid.size();
	ll n=grid[0].size();
	vector<vector<ll>> heights(m,vector<ll>(n,-1));
	for(ll i=0;i<m;i++){
		for(ll j=0;j<n;j++){
			if(grid[i][j]==1){
				q.push({i,j});
				heights[i][j]=0;
			}
		}
	}
	while(q.empty()==false){	

		ll x=q.front().first;
		ll y=q.front().second;
		q.pop();
		for(ll i=0;i<4;i++){
			ll new_x=x+dx[i];
			ll new_y=y+dy[i];
			if(new_x<0 or new_x>=m or new_y<0 or new_y>=n)
				continue;
			if(heights[new_x][new_y]!=-1)
				continue;
			heights[new_x][new_y]=heights[x][y]+1;
			q.push({new_x,new_y});
		}
	}
	return heights;

}

int main(){
	
	ll m,n;
	cin>>m>>n;
	vector<vector<ll>> grid(m,vector<ll>(n,0));
	for(ll i=0;i<m;i++){
		for(ll j=0;j<n;j++){
			cin>>grid[i][j];
		}
	}
	vector<vector<ll>> heights=solve(grid);
	for(ll i=0;i<m;i++){
		for(ll j=0;j<n;j++){
			cout<<heights[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
