#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin>>n;
    int ans = 1000 - (n % 1000);
    ans = ans % 1000;
    cout << ans << endl;
    return 0;
}