#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main(){
    int a, b, k;
    cin >> a >> b >> k;
    int dp[a +b+ 1][a+b+1];
    for (int i = 0; i <= a+b; i++)
    {
        for (int j = 0; j <= a+b; j++)
        {
            dp[i][j] = 0;
            if ((i == j) || (j == 0))
            {
                dp[i][j] = 1;
            }
            else if (j < i)
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }
    int useda = 0, usedb = 0;
    for (int i = 0; i < (a + b);i++){
        int ifa = dp[a+b - useda-usedb - 1][b - usedb];
        int ifb = dp[a +b - useda -usedb -1 ][b - usedb-1];
        if(k<=ifa){
            useda++;
            cout << "a";
        }
        else{
            usedb++;
            cout << "b";
            k -= ifa;
        }
    }
    cout << endl;
    return 0;
}