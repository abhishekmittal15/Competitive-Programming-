#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int n,ans=0;
    cin>>n;
    int a[n];
    int remainders[200]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
        remainders[a[i]%200]++;
    }
    for(int i=0;i<200;i++)
        ans+=((remainders[i]*(remainders[i]-1))/2);
    cout<<ans<<endl;
    return 0;
}