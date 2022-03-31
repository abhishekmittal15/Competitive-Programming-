#include<iostream>
#include<vector>
using namespace std;

int solve(string s){

	vector<int> f(256,-1);
	int len = s.length();
	int start=-1,ans=0;
	for(int i=0;i<len;i++){
	
		if(f[s[i]] > start)
			start = f[s[i]];
		f[s[i]] = i;
		ans = max(ans,i-start);
	
	}
	
	return ans;

}

int main(){

	string s;
	cin>>s;
	int ans = solve(s);
	cout<<ans<<endl;
	return 0;

}
