#include<iostream>
#include<vector>
using namespace std;
#define int long long int 

signed main(){
	int n,m;
	cin>>n>>m;
	vector<int> noodles(n);
	vector<int> days(m);
	for(int i=0;i<n;i++){
		cin>>noodles[i];
	}
	for(int i=0;i<m;i++){
		cin>>days[i];
	}
	bool ans=true;
	for(int i=0;i<m;i++){
		int req=days[i];
		bool flag=false;
		for(int j=0;j<n;j++){
			if(noodles[j]==req){
				noodles[j]=-1;
				flag=true;
				break;
			}
		}
		ans=ans&flag;
	}
	if(ans){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	return 0;
}

