#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        n = (n % 2) ? n + 1 : n;
        int ans = (n * 5 )/ 2;
        if(n<6)
            ans = 15;
        cout << ans << endl;
    }
    return 0;
}