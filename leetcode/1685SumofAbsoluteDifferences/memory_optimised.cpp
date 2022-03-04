#include<iostream>
#include<vector>
using namespace std;
#define int long long int 

vector<int> solve(vector<int>& a){

	int n=a.size();
	vector<int> ans(n);
	int prefix_sum=0;
	for(int i=1;i<=n;i++){
	
		int current_element=a[i-1];
		prefix_sum+=current_element;
		ans[i-1]=i*current_element-prefix_sum;

	}
	int suffix_sum=0;
	for(int i=1;i<=n;i++){

		int current_element=a[n-i];
		suffix_sum+=current_element;
		ans[n-i]+=suffix_sum-i*current_element;
	
	}
	return ans;

}

signed main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int> ans=solve(a);
	for(int i=0;i<n;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
