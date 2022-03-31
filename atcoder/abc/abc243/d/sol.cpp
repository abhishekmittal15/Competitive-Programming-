#include<iostream>
using namespace std;

#define int long long int 

signed main(){

	double a=0,b=0,;
	int n,x;
	cin>>n>>x;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='U')
			a=a/2.0,b=b/2.0;
		if(s[i]=='R')
			a=a*2.0,b=2.0*b+1.0;
		if(s[i]=='L')
			a=a*2.0,b=b*2.0;
	}
	cout<<a<<" "<<b<<endl;
	cout<<(int)(a*x+b)<<endl;
	return 0;

}
