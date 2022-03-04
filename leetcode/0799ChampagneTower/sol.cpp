#include<iostream>
#include<vector>
using namespace std;

#define int long long int

float solve(int p,int qr,int qc){

	vector<vector<float>> dp(100,vector<float>(100,0.0));
	dp[0][0]=max(0LL,p);
	for(int i=1;i<100;i++){
		for(int j=0;j<i;j++){
			dp[i][j]+=max(0.0,((float)(dp[i-1][j])-1.0)/2.0);
			dp[i][j+1]+=max(0.0,((float)(dp[i-1][j])-1.0)/2.0);
		}
	}
	return min(1.0f,dp[qr][qc]);
}

signed main(){
	int p,qr,qc;
	cin>>p>>qr>>qc;
	float answer=solve(p,qr,qc);
	cout<<answer<<endl;
	return 0;
}
