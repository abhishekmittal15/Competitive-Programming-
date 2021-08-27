#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long int 
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        int sum = 0;
        cin >> n >> k >> x;
        vector<int> a(n);
        for (int i = 0;i<n;i++)
            cin >> a[i], sum += a[i];
        sort(a.begin(), a.end());
        for (int i = n - 1; i >= 1; i -= 2)
        {
            if (k <= 0)
                break;
            if (a[i] + a[i - 1] > x)
                k--, sum -= (a[i] + a[i - 1] - x);
            else
                break;
        }
        cout << sum << endl;
    }
    return 0;
}