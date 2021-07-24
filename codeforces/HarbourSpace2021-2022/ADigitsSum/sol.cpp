#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        int ans = (n + 1) / 10;
        cout << ans << endl;
    }
    return 0;
}