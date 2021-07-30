#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(string s){
    int n = s.length();
    int ans = 0;
    vector<vector<int>> pref(n+1, vector<int>(10, 0));
    for (int i = 1;i<=n;i++){
        char ch = s[i-1];
        pref[i] = pref[i - 1];
        pref[i][ch - 'a']++;
    }
    for (int i = 1; i <=n; i++)
    {
        for (int j = i; j <=n; j++)
        {
            int odd = 0;
            for (int k = 0; k < 10; k++)
                if ((pref[j][k] - pref[i-1][k]) % 2)
                    odd++;
            if (odd <= 1)
                ans++;
        }
    }
    return ans;
}
signed main(){
    string s;
    cin>>s;
    int ans = solve(s);
    cout << "Answer : " << ans << endl;
    return 0;
}