#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

bool solve(string s,string t){

	ll s_pos=0;
	for(ll i=0;i<t.length();i++){
		char s_char=s[s_pos];
		if(t[i]==s_char)
			s_pos++;
	}
	return s_pos==s.length();

}

int main(){
	string s,t;
	cin>>s>>t;
	bool answer=solve(s,t);
	cout<<answer<<endl;
	return 0;
}
