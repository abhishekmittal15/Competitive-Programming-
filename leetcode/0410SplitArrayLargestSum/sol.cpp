#include<iostream>
#include<vector>
using namespace std;

bool check(const vector<int>& a, int m, int mid){

	int sum = 0;
	int n = a.size();
	for(int i=0;i<n;i++){
		sum += a[i];
		if(sum > mid)
			m--,sum = a[i];
	}
	return m>=0;

}

int solve(const vector<int>& a,int m){

	int n = a.size();
	int start = 1;
	int end = 0;
	for(auto i: a)
		start = max(start,i),end += i;
	const int inf = 1e9+5;
	int ans = inf;
	while(start <= end){
	
		int mid = ( start + end )/2;
		if(check(a,m - 1,mid)){
			ans = mid, end = mid - 1;
			cout<<ans<<endl;
		}
		else
			start = mid + 1;

	}
	return ans;

}

int main(){

	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(auto &i: a)
		cin>>i;
	int ans = solve(a,m);
	cout<<ans<<endl;
	return 0;

}
