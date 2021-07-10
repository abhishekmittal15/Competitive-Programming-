#include<iostream>
#include<algorithm>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    while(t--){
        int d,x,y,z;
        cin>>d>>x>>y>>z;
        int ans = max(x * 7, y * d + (7 - d) * z);
        cout<<ans<<endl;
    }
    return 0;
}