#include<iostream>
#include<vector>
using namespace std;

#define int long long int 

signed main(){

	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		string s;
		cin>>s;
		int len = s.length();
		string ans = "Bob";
		if (s[len-1]=='A' or s[len-1]=='E' or s[len-1]=='I' or s[len-1]=='O' or s[len-1]=='U' or s[len-1]=='a' or s[len-1]=='e' or s[len-1]=='i' or s[len-1]=='o' or s[len-1]=='u')
			ans = "Alice";
		if (s[len-1] == 'y' or s[len-1] == 'Y')
			ans = "nobody";
		cout<<"Case #"<<i<<": "<<s<<" is ruled by "<<ans<<"."<<endl;
	}
	return 0;

}

