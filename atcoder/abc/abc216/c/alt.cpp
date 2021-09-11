#include <bits/stdc++.h>
#define ll long long int
#define INF (ll)1e18 + 7
#define MOD 1000000007
#define DEBUG(x) cerr<<'>'<<#x<<':'<<x<< endl
using namespace std;
#define int long long

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

void solve() {
    int n;
    cin >> n;
    string s = bitstring(n);
    int size = s.length();
    /* cout << size << " " << s << " " << s.length() << endl; */
    int i = 0;
    while(i < size and s[i] == '0') {
        i++;
    }
    bool flag = false;
    for(; i < size; i++) {
        if(s[i] == '1') {
            if(flag)
                cout << "BA";
            else {
                cout << "A";
                flag = true;
            }
        } else {
            cout << "B";
        }
    }
    return;
}

signed main() {

    int T = 1;
    while(T--) {
        solve();
    }
    return 0;
}