#include<iostream>
#include<vector>
using namespace std;

int main(){

	vector<vector<int>> a;
	a.push_back({1,2,3});
	for(int i=0;i<a.size();i++)
		for(int j=0;j<a[i].size();j++)
			cout<<a[i][j]<<endl;
	return 0;

}
