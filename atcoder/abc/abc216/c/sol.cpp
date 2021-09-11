#include<iostream>
#include<vector>
#include<math.h>
#define int long long int
using namespace std;
int inf = 1e18 + 5;

string bitstring(int n) {
    int size = ceil(log2(n));
    string s = "";
    for (int i = size; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            s.append("1");
        else
            s.append("0");
    }
    return s;
}

signed main() {
    int n;
    cin >> n;
    string s = bitstring(n);
    int size = s.length();
    int i = 0;
    while (i < size and s[i] == '0')
    {
        i++;
    }
    bool flag = false;
    for (; i < size; i++)
    {
        if (s[i] == '1')
        {
            if (flag)
                cout << "BA";
            else
            {
                cout << "A";
                flag = true;
            }
        }
        else
        {
            cout << "B";
        }
    }
    return 0;
}