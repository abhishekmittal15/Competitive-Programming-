#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
#define int long long int
signed main()
{
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; t++)
    {
        int n;
        cin >> n;
        double ans = (double)(n) / 2.0 + 0.5;
        cout << "Case #" << t << ": " << setprecision(100) << ans << endl;
    }
}