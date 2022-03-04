#include<iostream>
using namespace std;
#define int long long int 
int mod=1e9+7;

int binpow(int a,int b){
	int ans=1;
	while(b>0){
		if(b&1)
			ans=(ans*a)%mod;
		a=(a*a)%mod;
		b=b/2;
	}
	return ans;
}

int solve(int n){
	int answer=0;
	/* if(n%2){ */
	/* 	int current_answer=(binpow(2,n/2-1)*3)%mod; */
	/* 	answer=max(answer,current_answer); */
	/* } */
	/* else{ */
	/* 	int current_answer=binpow(2,n/2); */
	/* 	answer=max(answer,current_answer); */
	/* } */
	if(n%3==0){
		int current_answer=binpow(3,n/3);
		answer=max(answer,current_answer);
	}
	else if(n%3==1){
		int current_answer=(binpow(3,n/3-1)*4)%mod;
		answer=max(answer,current_answer);
	}
	else{
		int current_answer=(binpow(3,n/3)*2)%mod;
		answer=max(answer,current_answer);
	}
	return answer;
}

signed main(){
	int n;
	cin>>n;
	cout<<binpow(3,6)<<endl;
	int answer=solve(n);
	cout<<answer<<endl;
	return 0;
}
