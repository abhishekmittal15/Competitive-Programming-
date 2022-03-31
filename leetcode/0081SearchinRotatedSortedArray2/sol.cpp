#include<iostream>
#include<vector>
using namespace std;

inline bool existInFirst(vector<int>& a,int num){

	return a[0]<=num;

}

bool solve(vector<int>& a, int target){

	int n = a.size();
	int start = 0;
	int end = n-1;
	while(start <= end){
	
		int mid = (start+end)/2;
		if(a[mid] == target)
			return true;

		bool mid_in_f = existInFirst(a,a[mid]);
		bool target_in_f = existInFirst(a,target);
		if(mid_in_f and target_in_f)
			if(a[mid]<target)
				start = mid + 1;
			else
				end = mid - 1;
		if(mid_in_f and !target_in_f)
			start = mid + 1;
		if(!mid_in_f and target_in_f)
			end = mid - 1;
		if(!mid_in_f and !target_in_f)
			if(a[mid]<target)
				start = mid + 1;
			else
				end = mid - 1;
		
	}
	return false;

}

int main(){

	int n,target;
	cin>>n>>target;
	vector<int> a(n);
	for(auto &i:a)
		cin>>i;
	bool ans = solve(a,target);
	cout<<ans<<endl;
	return 0;

}
