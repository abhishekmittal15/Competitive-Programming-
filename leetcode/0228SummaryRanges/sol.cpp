#include<iostream>
#include<vector>
#include<string>
using namespace std;

/* inline int sz(vector<a) */

#define sz(a) ((int)(a.size()))

#define int long long int

vector<string> solve(vector<int>& nums){

	vector<string> answer;
	nums.push_back(-1e9);
	int n=nums.size();
	if(n==0)
		return answer;
	int start=nums[0];
	int end=1e15;
	if(n==1){
		answer.push_back(to_string(start));
		return answer;
	}
	for(int i=1;i<n;i++){
		if(nums[i]!=nums[i-1]+1){
			if(start==nums[i-1])
				answer.push_back(to_string(start));
			else
				answer.push_back(to_string(start)+"->"+to_string(nums[i-1]));
			start=nums[i];
		}
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
	vector<string> answer=solve(a);
	for(int i=0;i<sz(answer);i++){
		cout<<answer[i]<<endl;
	}
	return 0;
}
