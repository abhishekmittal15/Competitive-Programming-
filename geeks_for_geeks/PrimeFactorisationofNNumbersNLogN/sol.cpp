#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
void s(int n,vector<bool>& sieve,vector<int>& spf){
    for (int i = 2; i * i <= n;i++){
        if(sieve[i]){
            for (int j = i * i; j <= n;j+=i){
                if(sieve[j])
                    spf[j] = i;
                sieve[j] = false;
            }
        }
    }
}
vector<vector<int>> solve(int n){
    vector<bool> sieve(n + 1, true);
    vector<int> spf(n + 1);
    for (int i = 0; i <= n;i++)
        spf[i] = i;
    vector<vector<int>> prime_fac(n + 1);
    s(n, sieve, spf);
    for (int i = 1; i <= n;i++){
        int x=i;
        while(x!=1){
            prime_fac[i].push_back(spf[x]);
            x /= spf[x];
        }
    }
    return prime_fac;
}
signed main(){
    int n;
    cin>>n;
    vector<vector<int>> ans = solve(n);
    for (int i = 1; i <= n;i++){
        cout << i << " ->";
        for (int j = 0; j < ans[i].size();j++){
            cout << " " << ans[i][j];
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}