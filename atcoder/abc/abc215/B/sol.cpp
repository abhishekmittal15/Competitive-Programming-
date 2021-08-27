#include<iostream>
#include<math.h>
using namespace std;
// #define int long long int 
signed main(){
    long long int n;
    cin>>n;
    int ans = 0;
    while(n>1){
        n /= 2;
        ans++;
    }
    cout <<ans<<endl;
    return 0;
}