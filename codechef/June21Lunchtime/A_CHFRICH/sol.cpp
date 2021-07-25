#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    while(t--){
        int a, b, x;
        cin >> a >> b>>x;
        int ans = (b - a) / x;
        if((b-a)%x!=0)
            ans++;
        cout << ans << endl;
    }
    return 0;
}