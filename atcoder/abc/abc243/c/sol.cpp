#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

#define int long long int 

signed main(){

	int n;
	cin>>n;
	map<int,vector<pair<int,int>>> lines;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		lines[y].push_back({x,i});
	}
	string s;
	cin>>s;
	bool flag=false;
	for(auto &it:lines)
		sort(it.second.begin(),it.second.end());
	for(auto it:lines){
		auto line=it.second;
		bool r_seen=false;
		for(int i=0;i<line.size();i++){
			if(s[line[i].second]=='R')
				r_seen=true;
			if(r_seen==true and s[line[i].second]=='L')
				flag=true;
		}
	}
	if(flag)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;

}
