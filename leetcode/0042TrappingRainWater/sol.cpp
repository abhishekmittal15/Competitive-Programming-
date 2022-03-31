#include<iostream>
#include<vector>
using namespace std;

#define int long long int 

int f(vector<int>& h){

	int n=h.size();
	int ans=0;
	int prev=h[0];
	int prev_index=0;
	int black_sum=0;
	for(int i=1;i<n;i++){
		if(h[i]>=prev){
			ans+=((i-prev_index-1)*prev);
			ans-=black_sum;
			black_sum=0;
			prev_index=i;
			prev=h[i];
		}
		else{
			black_sum+=h[i];
		}
	}
	return ans;
}

int solve(vector<int>& h){

	int ans=0;
	int max_height=0;
	int n=h.size();
	for(int i=0;i<n;i++){
		max_height=max(max_height,h[i]);
	}
	int first_index=0;
	int last_index=n-1;
	while(h[first_index]<max_height)
		first_index++;
	while(h[last_index]<max_height)
		last_index--;
	vector<int> left,right;
	for(int i=0;i<=first_index;i++)
		left.push_back(h[i]);
	for(int i=n-1;i>=last_index;i--)
		right.push_back(h[i]);
	ans=f(right)+f(left);
	if(last_index>first_index)
		ans+=(last_index-first_index-1)*max_height;
	return ans;

}

signed main(){

	int n;
	cin>>n;
	vector<int> h(n,0);
	for(int i=0;i<n;i++)
		cin>>h[i];
	int ans=solve(h);
	cout<<ans<<endl;
	return 0;

}
