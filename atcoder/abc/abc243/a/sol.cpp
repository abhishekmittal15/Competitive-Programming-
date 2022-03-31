#include<iostream>
#include<vector>
using namespace std;
#define int long long int 

signed main(){

	int v,a,b,c;
	cin>>v>>a>>b>>c;
	v=v%(a+b+c);
	if(v<a)
		cout<<"F"<<endl;
    else if(v<a+b)
		cout<<"M"<<endl;
	else
		cout<<"T"<<endl;
	return 0;

}
