#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    while(t--){
        int g1, g2, b1, b2, s1, s2;
        cin >> g1 >> s1 >> b1 >> g2 >> s2 >> b2;
        int ans = (g1 + s1 + b1) > (g2 + b2 + s2);
        if(ans==0)
            ans = 2;
        cout << ans << endl;
    }
    return 0;
}