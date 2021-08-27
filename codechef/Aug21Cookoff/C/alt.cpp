#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define int long long int 
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> m;
        set<int> s;
        for (int i=0;i<n;i++)
        {
            cin >> a[i];
            m[a[i]]++;
            if (a[i] != 1 and a[i] != 0)
                s.insert(a[i]);
        }

        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }

        if (s.empty())
        {
            cout << 1 << endl;
            continue;
        }
        else if (s.size() > 1)
        {
            cout << 0 << endl;
            continue;
        }
        else
        {
            int num = *(s.begin());
            if (m[num] > 1 && num != -1)
                cout << 0 << endl;
            else if (m[num] > 1 && num == -1)
            {
                if (m[1] >= 1)
                    cout << 1 << endl;
                else
                    cout << 0 << endl;
            }
            else
            {
                cout << 1 << endl;
            }
        }
    }
    return 0;
}