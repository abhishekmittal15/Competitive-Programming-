#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    string s, t;
    cin >> s >> t;
    string ans = (s < t) ? "Yes" : "No";
    cout << ans << endl;
    return 0;
}