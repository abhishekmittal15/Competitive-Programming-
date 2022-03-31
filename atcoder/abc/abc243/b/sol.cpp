#include<iostream>
#include<vector>
using namespace std;

#define int long long int 

signed main(){

	int cnt1=0,cnt2=0;
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	for(int i=0;i<n;i++)
		if(a[i]==b[i])
			cnt1++;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)
				continue;
			if(a[i]==b[j])
				cnt2++;
		}
	}
	cout<<cnt1<<endl;
	cout<<cnt2<<endl;
	return 0;

}
				
