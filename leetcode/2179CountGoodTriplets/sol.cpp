#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

int solve(vector<int>& a,vector<int>& b){

	int ans = 0;
	int n = a.size();
	unordered_set<int> exists_a, exists_b;
	vector<int> r_com, l_com;
	int ctr = 0;
	// Find the number of elements common from the left of the element
	for(int i = 0; i < n; i++){
		l_com.push_back(ctr);
		exists_a.insert(a[i]);
		if(exists_a.find(b[i]) != exists_a.end())
			ctr++;
		else
			exists_b.insert(b[i]);
		if(exists_b.find(a[i]) != exists_b.end())
			ctr++;
	}
	ctr = 0;
	exists_a.clear();
	exists_b.clear();
	// Find the number of elements common from the right of the element
	for(int i = n-1; i >= 0; i--){
		r_com.push_back(ctr);
		exists_a.insert(a[i]);
		if(exists_a.find(b[i]) != exists_a.end())
			ctr++;
		else
			exists_b.insert(b[i]);
		if(exists_b.find(a[i]) != exists_b.end())
			ctr++;
	}
	
	reverse(r_com.begin(),r_com.end());

	for(int i = 0; i < n; i++)
		cout << l_com[i]<< " ";
	cout << endl;
	for(int i = 0; i < n; i++)
		cout << r_com[i] << " ";
	cout << endl;

	for(int i = 1; i < n-1; i++)
		ans+=(r_com[i]*l_com[i]);

	return ans;

}

int main(){

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int &i : a)
		cin >> i;
	for(int &i : b)
		cin >> i;
	int ans = solve(a,b);
	cout << ans << endl;
	return 0;

}
