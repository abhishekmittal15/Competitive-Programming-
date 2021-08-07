#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(int n){
    vector<int> f;
    f.push_back(0);
    f.push_back(1);
    for (int i = 2; i <=n;i++)
        f.push_back(f[i - 1] + f[i - 2]);
    return f[n];
}
signed main(){
    int n;
    cin>>n;
    int ans = solve(n);
    cout << "Answer : " << ans << endl;
    return 0;
}