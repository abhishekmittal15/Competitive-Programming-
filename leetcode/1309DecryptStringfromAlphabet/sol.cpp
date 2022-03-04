#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

typedef long long ll;

string solve(string s){

	reverse(s.begin(),s.end());
	string answer;
	for(ll i=0;i<s.length();i++){
	
		if(s[i]=='#'){
			ll offset=s[i+1]-'0'+10*(s[i+2]-'0');
			answer.push_back('a'+offset-1);
			i+=2;
		}
		else{
			answer.push_back('a'+s[i]-'0'-1);
		}

	}
	reverse(answer.begin(),answer.end());
	return answer;
}

int main(){
	string s;
	cin>>s;
	string answer=solve(s);
	cout<<answer<<endl;
	return 0;
}

