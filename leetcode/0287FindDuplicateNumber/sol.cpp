#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>& a){

	int slow = 0;
	int fast = 0;
	while (true){
		slow = a[slow];
		fast = a[a[fast]];
		if (slow == fast)
			break;
	}
	slow = 0;
	while(slow != fast){
		slow = a[slow];
		fast = a[fast];
	}
	return slow;

}

int main(){

	int n;
	cin>>n;
	vector<int> a(n,0);
	for(auto &i:a)
		cin>>i;
	int ans = solve(a);
	cout<<ans<<endl;
	return 0;

}
