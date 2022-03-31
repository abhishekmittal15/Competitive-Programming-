#include<iostream>
#include<vector>
using namespace std;

int solve (vector<int> &a, int target){
	
	int n = a.size();
	int start = 0;
	int end = n-1;
	while ( start <= end ){
		int mid = (start+end)/2;
		if( a[mid] == target )
			return mid;
		else if( a[mid] < target )
			start = mid+1;
		else
			end = mid-1;
	}
	return -1;

}

int main(){

	int n,target;
	cin>>n>>target;
	vector<int> a(n);
	for(auto &i: a)
		cin>>i;
	int ans = solve(a,target);
	cout<<ans<<endl;
	return 0;
}
