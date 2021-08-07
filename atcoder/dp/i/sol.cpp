#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin>>n;
    vector<double> p(n+1,0.0);
    for(int i=1;i<=n;i++)
        cin>>p[i];
    vector<vector<double>> dp(n+1,vector<double>(n+1,0));
    dp[0][0]=1.0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i+j>n)
                continue;
            if(i==0 && j==0)
                continue;
            if(i>0)
                dp[i][j]=dp[i-1][j]*p[i+j];
            if(j>0)
                dp[i][j]+=dp[i][j-1]*(1-p[i+j]);
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=n;j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    double ans=0;
    for(int i=0;i<=n;i++)
        if(i>(n-i))
            ans+=dp[i][n-i];
    cout<<setprecision(10)<<ans<<endl;
    return 0;
}