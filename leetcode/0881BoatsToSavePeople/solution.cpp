#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int>& a,int limit){

	sort(a.begin(),a.end());
	int n=a.size();
	int l=0,r=n-1;
	int ans=0;
	while(l<=r){
		if(a[l]+a[r]<=limit)
			l++;
		r--;
		ans++;
	}
	return ans;

}

int main(){

	int n,limit;
	cin>>n>>limit;
	vector<int> a(n,0);
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ans=solve(a,limit);
	cout<<ans<<endl;
	return 0;

}
