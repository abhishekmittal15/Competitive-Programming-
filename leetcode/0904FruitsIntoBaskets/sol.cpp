#include<iostream>
#include<vector>
#include<map>
using namespace std;

int solve(vector<int>& fruits){

	int n = fruits.size();
	map<int,int> cnt;
	int ans = 0;
	for(int i = 0; i < n; i++){
		
		int curr = fruits[i];
		if(cnt.find(curr) == cnt.end()){
			cnt[curr] = 1;
		}
		else
			cnt[curr]++;
		if(cnt.size()>2){
			int key_to_del;
			for(auto it: cnt)
				if(it.first != curr and it.first != fruits[i-1])
					key_to_del = it.first;
			cnt.erase(key_to_del);
		}
		int sum = 0;
		cout<<"----"<<endl;
		cout<<i<<endl;
		for(auto it: cnt){
			cout<<it.first<<"->"<<it.second<<endl;
			sum += it.second;
		}
		ans = max(ans,sum);
	}	
	return ans;
	
}

int main(){

	int n;
	cin>>n;
	vector<int> fruits(n);
	for(auto &i:fruits)
		cin>>i;
	int ans = solve(fruits);
	cout << ans << endl;
	return 0;

}
