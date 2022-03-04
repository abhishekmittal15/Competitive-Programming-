#include<iostream>
#include<vector>
using namespace std;
#define int long long int 

vector<int> solve(vector<int>& a){

	int n=a.size();
	vector<int> prefix(n+1,0);
	for(int i=1;i<=n;i++){
		prefix[i]=prefix[i-1]+a[i-1];
	}
	vector<int> answer(n);
	for(int i=1;i<=n;i++){
		int current_element=a[i-1];
		answer[i-1]=i*current_element-prefix[i];
		answer[i-1]+=(prefix[n]-prefix[i]-(n-i)*current_element);
	}
	return answer;
}

signed main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int> answer=solve(a);
	for(int i=0;i<n;i++){
		cout<<answer[i]<<endl;
	}
	return 0;
}
