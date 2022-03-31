#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> solve(const vector<vector<int>>& grid, int k){
	
	int m=grid.size();
	int n=grid[0].size();
	vector<pair<int,int>> temp;
	for(int i=0;i<m;i++){
		int cnt = lower_bound(grid[i].begin(),grid[i].end(),0,greater<int>())-grid[i].begin();	
		temp.push_back({cnt,i});
	}
	sort(temp.begin(),temp.end());
	vector<int> ans;
	for(int i=0;i<k;i++)
		ans.push_back(temp[i].second);
	return ans;

}

int main(){

	int m,n,k;
	cin>>m>>n>>k;
	vector<vector<int>> grid(m,vector<int>(n,0));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>grid[i][j];
	vector<int> ans=solve(grid,k);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;

}
