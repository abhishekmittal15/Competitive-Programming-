#include<iostream>
#include<vector>
using namespace std;
#define int long long int 

int solve(string a,string b){
    int n=a.length();
    int m=b.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return m+n-dp[n][m];
}

signed main(){
    string a,b;
    cin>>a>>b;
    int length=solve(a,b);
    cout<<length<<endl;
    return 0;
}