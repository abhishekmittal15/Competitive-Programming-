#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int> solve(vector<int>& a,int k){

	vector<int> result;
	unordered_map<int,int> umap;
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
	int n = a.size();
	for(int i = 0; i < n; i++){	
		if(umap.find(a[i]) == umap.end())
			umap[a[i]] = 0;
		umap[a[i]]++;
	}

	for(auto it: umap){
		pq.push({it.second,it.first});
		if(pq.size()>k)
			pq.pop();
	}

	while(!pq.empty()){
		result.push_back(pq.top().second);
		pq.pop();
	}
	return result;

}

int main(){

	int n,k;
	cin >> n >> k;
	vector<int> a(n);
	for(int &i: a)
		cin >> i;
	vector<int> ans = solve(a,k);
	for(int i : ans)
		cout << i << endl;
	return 0;

}
