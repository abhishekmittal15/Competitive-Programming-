#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    string s;
    cin>>s;
    int n = s.length();
    int dp[n];
    dp[0] = s[0] != '0';
    for (int i = 1; i < n;i++){
        if(s[i]=='0')
            dp[i] = 0;
        if(s[i]!='0')
            dp[i] = dp[i - 1];
        if(s[i-1]!='0'){
            int num = (s[i - 1] - '0') * 10 + s[i] - '0';
            if(num<=26){
                if(i>1)
                dp[i] += dp[i - 2];
                else
                    dp[i]++;
            }
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}