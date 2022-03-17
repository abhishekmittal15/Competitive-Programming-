#include<iostream>
#include<vector>

using namespace std;
#define int long long int 

signed main(){
	string sans="No";
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int length=j-i+1;
			bool is_palindrome=true;
			for(int l1=i,l2=j;l1<=j;l1++,l2--)
				if(s[l1]!=s[l2]){
					is_palindrome=false;
				}
			if(is_palindrome==true and length%2==0){
				cout<<"Or not."<<endl;
				return 0;
			}
		}
	}
	cout<<"Odd."<<endl;
	return 0;
}
