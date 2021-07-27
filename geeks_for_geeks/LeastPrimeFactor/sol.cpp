#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
void s(int n,vector<bool>& sieve,vector<int>& result){
    for (int i = 2; i * i <=n;i++){
        if(sieve[i]){
            for (int j = i * i; j <= n;j+=i){
                if(sieve[j]==true){
                    result[j] = i;
                }
                sieve[j] = false;
            }
        }
    }
}
vector<int> solve(int n){
    vector<int> result(n+1,0);
    vector<bool> sieve(n+1,true);
    for (int i = 0; i <= n;i++)
        result[i] = i;
    s(n, sieve, result);
    vector<int> temp;
    for (int i = 1; i < result.size(); i++)
        temp.push_back(result[i]);
    return temp;
}
signed main(){
    int n;
    cin>>n;
    vector<int> ans = solve(n);
    for (int i = 0; i < ans.size();i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}