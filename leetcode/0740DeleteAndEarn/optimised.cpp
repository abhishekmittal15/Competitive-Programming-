#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long int 

int solve(vector<int>& a){
	int n=a.size();
	vector<int> freq((int)(1e4)+1,0);
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++)
		freq[a[i]]++;
	int ans_0=0;
	int ans_1=0;
	for(int i=0;i<n;i++){
		int a_i=a[i];
		int aans_1=ans_1;
		int aans_0=ans_0;
		ans_1=aans_0+(a_i*freq[a_i]);
		ans_0=max(aans_0,aans_1);
	}
	return max(ans_0,ans_1);
}

signed main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=solve(a);
	cout<<ans<<endl;
	return 0;
}
