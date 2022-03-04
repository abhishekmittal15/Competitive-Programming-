#include<iostream>
#include<vector>
using namespace std;

#define int long long int 
signed main(){
	vector<int> a(10);
	for(int i=0;i<10;i++)
		cin>>a[i];
	cout<<a[a[a[0]]]<<endl;
	return 0;
}
