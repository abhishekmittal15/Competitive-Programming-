#include<iostream>
#include<vector>
using namespace std;
#define int long long int
bool validity(vector<int> &config1, vector<int> &config2,int m){
    for (int i = 0; i < m;i++){
        if(config1[i]==config2[i])
            return false;
    }
    return true;
} 
int solve(int m, int n)
{
    int mx = 1;
    for (int i = 0; i < m;i++)
        mx = mx * 3;
    int mod = 1000 * 1000 * 1000 + 7;
    vector<vector<int>> validconfigs;
    for (int i = 0; i < mx;i++){
        vector<int> temp;
        int current = i;
        for (int j = 0; j < m;j++){
            temp.push_back(current % 3);
            current /= 3;
        }
        bool valid = true;
        for (int j = 1; j < m;j++){
            if(temp[j]==temp[j-1])
                valid = false;
        }
        if(valid)
            validconfigs.push_back(temp);
    }
    mx = validconfigs.size();
    int dp[n][mx];
    for (int i = 0; i < mx;i++){
        dp[0][i] = 1;
    }
    for (int i = 1; i < n;i++){
        for (int j = 0; j < mx;j++){
            dp[i][j] = 0;
            for (int k = 0; k < mx;k++){
                if(validity(validconfigs[j],validconfigs[k],m)){
                    dp[i][j] = (dp[i][j]+ dp[i - 1][k])%mod;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < mx;i++){
        ans = (ans + dp[n - 1][i]) % mod;
    }
    return ans;
}
signed main(){
    int m, n;
    cin >> m >> n;
    int answer = solve(m, n);
    cout << "Answer : " << answer << endl;
    return 0;
}