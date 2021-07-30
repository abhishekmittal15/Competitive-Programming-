// (x^a) | (x^b)

// if x is 1 then a ^ b
// if x is 0 then also a ^ b

// a b nota notb a|b nota|notb
// 0 0  1     1   0      1
// 1 0  0     1   1      1
// 0 1  1     0   1      1
// 1 1  0     0   1      0

// 0 only when both are 0 and x is 0, and 1 only when both are 1 and x is also 1
// so basically it is x^(a | b)

#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin >> t;
    while(t--){int n;
    cin>>n;
    int a[n];
    int mx = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(a[i],mx);
    }
    int ans=0;
    for(int i=0;i<n;i++)
        ans|=(a[i]^mx);
    cout<<mx<<" "<<ans<<endl;
    }
    return 0;
}