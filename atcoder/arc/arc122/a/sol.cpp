#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int mod = 1e9 + 7;
signed main(){
    int n;
    cin >> n;
    int ways[n][2];
    int sum[n][2];
    int cumsum[n];
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
        if(i==0){
            ways[i][0] = 1;
            ways[i][1] = 0;
            sum[i][0] = a[i];
            sum[i][1] = 0;
        }
        else{
            ways[i][0] = (ways[i - 1][0] + ways[i - 1][1])%mod;
            ways[i][1] = ways[i - 1][0];
            sum[i][0] = ((ways[i][0] * a[i])%mod + cumsum[i - 1])%mod;
            sum[i][1] = ((-1 * ways[i][1] * a[i]+mod) + sum[i-1][0])%mod;
        }
        cumsum[i] = (sum[i][0] + sum[i][1])%mod;
    } 
    cout << cumsum[n-1] << endl;
    return 0;
}