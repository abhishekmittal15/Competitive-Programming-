#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n=100;
    vector<int> dp(n + 1,false);
    for (int i = 1;i<=n;i++){
        vector<int> divisors;
        for (int j = 2;j<i;j++)
            if(i%j==0)
                divisors.push_back(j);
        bool flag = true;
        for (int j = 0; j < divisors.size();j++)
            flag = flag & dp[i - divisors[j]];
        dp[i] = !flag;
    }
    for (int i = 1;i<=n;i++){
        string ans = "";
        if(dp[i])
            ans = "Alice";
        else
            ans = "Bob";
        cout<<i<<" "<<ans<<endl;
    }
    return 0;
}