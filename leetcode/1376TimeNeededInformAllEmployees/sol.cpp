#include<iostream>
#include<vector>
using namespace std;

int dfs(int u,vector<vector<int>>& adj,vector<int>& informTime){

	int ans = 0;
	for(auto v: adj[u])
		ans = max(ans,dfs(v,adj,informTime));
	return ans+informTime[u];

}

int solve(int n,int head, vector<int>& managers, vector<int>& informTime){

	vector<vector<int>> adj(n);
	for(int i = 0;i<n;i++){
		if(managers[i] == -1)
			continue;
		adj[managers[i]].push_back(i);
	}
	/* for(int i = 0; i < n; i++){ */
	/* 	cout<<i<<"->"; */
	/* 	for(auto j: adj[i]) */
	/* 		cout<<j<<" "; */
	/* 	cout<<endl; */
	/* } */
	int ans = dfs(head,adj,informTime);
	return ans;

}

int main(){

	int n;
	cin>>n;
	vector<int> managers(n);
	vector<int> informTime(n);
	int head;
	for(auto &i: managers)
		cin>>i;
	for(auto &i: informTime)
		cin>>i;
	cin>>head;
	int ans = solve(n,head,managers,informTime);
	cout<<ans<<endl;
	return 0;

}
