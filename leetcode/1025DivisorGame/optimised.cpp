#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
bool solve(int n){
    return (n % 2);
}
signed main(){
    int n;
    cin>>n;
    bool ans = solve(n);
    cout << "Answer : " << ans << endl;
    return 0;
}