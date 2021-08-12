#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int n_;
    cin>>n_;
    for (int n = 1; n <= n_;n++){
        int ans = (n * n) * (n * n - 1) / 2;
    ans -= (4 * (n - 1) * (n - 2));
    cout << ans << endl;
    }
    return 0;
}