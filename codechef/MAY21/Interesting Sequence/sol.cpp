#include <iostream>
using namespace std;
// #define int long long int
int maxn = 4 * 1000 * 1000 + 1;
int p[maxn], a[maxn];
void calc()
{
    for (int i = 0; i < maxn; i++)
    {
        p[i] = i;
        a[i] = 0;
    }
    for (int ptr = 2; ptr < maxn; ptr++)
    {
        if (p[ptr] == ptr)
        {
            p[ptr] = ptr - 1;
            for (int i = 2 * ptr; i < maxn; i += ptr)
            {
                int temp = p[i] / ptr;
                temp = temp * (ptr - 1);
                p[i] = temp;
            }
        }
    }
}
void ans()
{
    for (int i = 1; i < maxn; i++)
    {
        a[i] += (i - 1);
        for (int j = 2 * i; j < maxn; j += i)
        {
            int temp = 1 + p[j / i];
            temp = temp / 2;
            temp = temp * i;
            a[j] += temp;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    calc();
    ans();
    int t;
    cin >> t;
    while (t--)
    {
        int var;
        cin >> var;
        int index = 4 * var;
        index++;
        int ans_var = a[index];
        cout << ans_var;
        cout << endl;
    }
    return 0;
}