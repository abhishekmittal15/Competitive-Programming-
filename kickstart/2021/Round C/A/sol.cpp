#include <bits/stdc++.h>
#define int long long int
int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
signed main()
{
    int t=625;
    for (int test = 1; test <= t; test++)
    {
        string s;
        int n=4, k=5;
        // cin >> n >> k;
        cin >> s;
        vector<int> kpowers;
        kpowers.push_back(1);
        int ans = 1;
        for (int i = 1; i <= (n / 2); i++)
            ans = (ans * k)%mod, kpowers.push_back(ans);
        ans = 0;
        int diff1, diff2, diff;
        for (int i = 0; i < ((n - 1) / 2); i++)
        {
            diff = s[i] - 'a';
            // diff1 = s[i] - 'a';
            // diff2 = s[n - i - 1] - 'a';
            // diff = min(diff1, min(diff2, k));
            ans += (diff * kpowers[(n - 1) / 2 - i]);
            ans = ans % mod;
        }
        ans += (s[(n - 1) / 2] - 'a');
        bool flag =false;
        for (int i = n/2-1; i>=0;i--){
            if(s[i]<s[n-i-1]){
                flag = true;
                break;
            }
            else if(s[i]==s[n-i-1])
                continue;
            else
                break;
        }
        if(flag)
            ans++;
        ans = ans % mod;
        if(n==1)
            ans = s[0] - 'a';
        cout << "Case #" << test << ": " << ans << endl;
    }
    return 0;
}