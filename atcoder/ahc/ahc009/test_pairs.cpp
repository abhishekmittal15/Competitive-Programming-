#include<iostream>
using namespace std;

int main(){

	pair<int,int> a = {-100,298};
	pair<int,int> b = {-100,298};
	pair<int,int> c = {-100,299};
	bool ans  = a == b;
	bool ans1 = a == c;
	cout << ans << endl;
	cout << ans1 << endl;
	return 0;


}
