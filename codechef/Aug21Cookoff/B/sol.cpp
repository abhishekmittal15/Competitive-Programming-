#include <iostream>
#include <map>
#include<algorithm>
using namespace std;
#define int long long int
string convert(int i, int n)
{
    string ans = "";
    for (int ptr = 0; ptr < n; ptr++)
    {
        if (i & (1 << ptr))
            ans += "1";
        else
            ans += "0";
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s[n];
        map<string, bool> p;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            p[s[i]] = true;
        }
        string cur;
        for (int i = 0; i < 1 << 10; i++)
        {
            cur = convert(i, n);
            if (p[cur])
                continue;
            else
                break;
        }
        cout << cur << endl;
    }
    return 0;
}