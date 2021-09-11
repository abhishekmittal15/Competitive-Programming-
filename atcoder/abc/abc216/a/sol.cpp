#include<iostream>
using namespace std;
#define int long long int 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    double s;
    cin >> s;

    int x = s;
    double y = s - (double)x;

    int val = 10 * y;
    if (val <= 2)
        cout << x  << '-' << endl;
    else if (val <= 6)
        cout << x << endl;
    else
        cout << x << '+' << endl;
    
    return 0;
}