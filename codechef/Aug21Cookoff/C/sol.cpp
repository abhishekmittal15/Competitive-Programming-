#include <iostream>
#include <vector>
using namespace std;
#define int long long int
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<int> a(n);
        int one = 0, negone = 0;
        int cnt = 0;
        int val = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == -1)
                negone++;
            else if (a[i] == 1)
                one++;
            else if (abs(a[i]) > 1)
            {
                val = a[i];
                cnt++;
            }
        }
        if (cnt > 1)
        {
            cout << 0 << endl;
            continue;
        }
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        bool flag1 = false, flag2 = false;
        if (cnt == 1)
        {
            if (negone > 0)
                for (int i = 0; i < n; i++)
                    if (a[i] == (-1ll*val))
                        flag1 = true;
            if (negone >= 2 && one > 0)
                flag2 = true;
        }
        if (flag1 && flag2)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
