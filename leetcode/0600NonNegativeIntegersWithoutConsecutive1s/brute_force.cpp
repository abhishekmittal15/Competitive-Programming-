#include<iostream>
using namespace std;
#define int long long int
bool check(int n){
    bool prev = false;
    while(n>0){
        bool cur = n % 2;
        if(prev & cur)
            return false;
        n /= 2;
        prev = cur;
    }
    return true;
} 
signed main(){
    int n;
    cin>>n;
    int ans = 0;
    for (int i = 0; i <=n; i++){
        if(check(i))
            ans++;
    }
    cout << ans << endl;
}