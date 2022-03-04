#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

typedef long long ll;

vector<int> solve(vector<int>& a,int k){

	int n=a.size();
	deque<int> temp;
	vector<int> ans;
	for(int i=0;i<k;i++){
		int current_element=a[i];
		while(temp.empty()==false and current_element>temp.front())
			temp.pop_front();
		temp.push_front(current_element);
	}
	for(int i=k;i<n;i++){
	
		int max_element=temp.back();
		ans.push_back(max_element);
		if(a[i-k]==max_element)
			temp.pop_back();
		int current_element=a[i];
		while(current_element>temp.front() && temp.empty()==false){
			temp.pop_front();
		}
		temp.push_front(current_element);
		
	}
	ans.push_back(temp.back());
	return ans;

}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int> answer=solve(a,k);
	for(int i=0;i<n-k+1;i++)
		cout<<answer[i]<<endl;
	return 0;
}
