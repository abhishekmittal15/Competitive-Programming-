#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

string solve(string s,int k){

	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	stack<pair<char,int>> characters;
	int n=s.length();
	for(int i=0;i<n;i++){
		if(!characters.empty() and characters.top().first==s[i]){
			characters.top().second++;
			if(characters.top().second==k)
				characters.pop();
		}
		else{
			characters.push({s[i],1});
		}
	}
	string ans;
	while(!characters.empty()){
		ans += string(characters.top().second, characters.top().first);
		characters.pop();
	}
	reverse(ans.begin(),ans.end());
	return ans;

}

int main(){

	string s;
	int k;
	cin>>s;
	cin>>k;
	string ans=solve(s,k);
	cout<<ans<<endl;
	return 0;

}
