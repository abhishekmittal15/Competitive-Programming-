#include<iostream>
#include<algorithm>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin >> x >> y;
        int gcd = __gcd(x, y);
        int ans;
        if(__gcd(x,y)>1)
            ans = 0;
        else if(__gcd(x+1,y)>1)
            ans = 1;
        else if(__gcd(x,y+1)>1)
            ans = 1;
        else if(__gcd(x+1,y+1)>1)
            ans = 2;
        cout << ans << endl;
    }
    return 0;
}