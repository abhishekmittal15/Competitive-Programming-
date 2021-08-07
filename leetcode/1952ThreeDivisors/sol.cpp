#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;
bool solve(ll n){
    int cnt = 0;
    for (ll i = 1; i * i <= n;i++){
        if(n%i==0)
            cnt += 2;
        if(i*i==n)
            cnt--;
    }
    return cnt == 3;
}
int main(){
    ll n;
    cin>>n;
    bool ans = solve(n);
    cout << "Answer : " << ans << endl;
    return 0;
}