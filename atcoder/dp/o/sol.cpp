#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int power(int a,int b){
    int ans = 1;
    while(b>0){
        if(b) ans*=a;
        a = a * a;
        b /= 2;
    }
    return ans;
}
signed main(){
    int n;
    cin>>n;
    vector<vector<int>> c(n, vector<int>(n, 0));
    for (int i = 0;i<n;i++)
        for (int j = 0; j < n;j++)
            cin >> c[i][j];
    int max_masks = power(2, n);
    vector<int> dp(max_masks,0);
    dp[0] = 1;
    for (int mask = 3; mask < max_masks;mask){
        for (int i = 0; i < n;i++)
            if(mask&(1<<i)){
                for (int j = 0; j < n;j++)
                    if(a[i][j])
                        dp[mask] += dp[mask ^ (1 << i)];
            }
        
        }
    }
    cout << dp.back();
}