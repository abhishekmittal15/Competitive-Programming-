#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int n,max=-1;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>max)
            max = a[i];
    }
    int dp[n]={2*a[0]};
    int maxold=a[0],maxnew=2*a[0];
    cout << dp[0] << endl;
    for(int i=1;i<n;i++){
        dp[i]=dp[i-1];
        if(a[i]>maxold){
            maxnew=maxnew+2*a[i]-maxold;
            dp[i]+=(i*(a[i]-maxold))+maxnew;
            maxold=a[i];
        }
        // cout <<i<<":"<<maxold << " " << maxnew << " " << dp[i] << endl;
        cout << dp[i] << endl;
    }
    return 0;
}