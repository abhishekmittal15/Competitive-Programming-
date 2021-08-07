#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin>>n;
    vector<int> h(n);
    for(int i=0;i<n;i++)
        cin>>h[i];
    int inf = 1e15;
    vector<int> dp(n,inf);
    dp[0]=0;
    for(int i=1;i<n;i++){
        if(i>=1)
            dp[i]=min(dp[i],dp[i-1]+abs(h[i]-h[i-1]));
        if(i>=2)
            dp[i]=min(dp[i],dp[i-2]+abs(h[i]-h[i-2]));
    }
    cout<<dp[n-1]<<endl;
    return 0;
}