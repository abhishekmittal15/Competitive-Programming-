#include<iostream>
#include<vector>
using namespace std;

int solve(const vector<int>& a){
	
	int n = a.size();
	vector<int> temp;
	for(int i=0;i<n;i++){
		int cur = a[i];
		// we are binary searching over the temp array
		int start = 0;
		int end = temp.size()-1;
		int index = -1;
		while(start <= end){
			int mid = (start + end)/2;
			if(temp[mid] >= cur)
				index = mid,end = mid - 1;
			else
				start = mid + 1;
		}
		// we find the first index whose value is greater than or equal to the current element and replace it with the current element
		if(index == -1)
			temp.push_back(cur);
		else
			temp[index] = cur;
		/* cout<<i<<" "<<a[i]<<" "<<index<<"->"; */
		/* for(int j=0;j<temp.size();j++) */
		/* 	cout<<temp[j]<<" "; */
		/* cout<<endl; */
	}
	return temp.size();

}

int main(){

	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &i: a)
		cin>>i;
	int ans = solve(a);
	cout<<ans<<endl;
	return 0;

}
