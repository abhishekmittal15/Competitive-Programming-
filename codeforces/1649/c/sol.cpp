#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long int 

signed main(){

	int n,m;
	cin>>m>>n;
	int max_sz=1e5+5;
	vector<vector<int>> colors_r(max_sz);
	vector<vector<int>> colors_c(max_sz);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int color;
			cin>>color;
			colors_r[color].push_back(i);
			colors_c[color].push_back(j);
		}
	}
	int answer=0;
	int pref=0;
	for(int i=0;i<max_sz;i++){
		pref=0;
		if(colors_r[i].size()>0){
			sort(colors_r[i].begin(),colors_r[i].end());
			for(int j=0;j<colors_r[i].size();j++){
				answer+=(j*colors_r[i][j]-pref);
				pref+=colors_r[i][j];
			}
			pref=0;
			sort(colors_c[i].begin(),colors_c[i].end());
			for(int j=0;j<colors_c[i].size();j++){
				answer+=(j*colors_c[i][j]-pref);
				pref+=colors_c[i][j];
			}
		}
	}
	cout<<answer<<endl;
	return 0;
}

