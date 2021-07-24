#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    string s;
    cin >> s;
    int distinct_char = 0;
    int n = s.length();
    vector<bool> visited(26, false);
    for (int i = 0; i < n; i++)
        if (visited[s[i] - 'a'] == false)
        {
            distinct_char++;
            visited[s[i] - 'a'] = true;
        }
    if (distinct_char == 1)
    {
        cout << n - 1 << endl;
        return 0;
    }
    if (distinct_char % 2)
    {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    vector<int> distinct_left(n, 0);
    vector<int> distinct_right(n, 0);
    distinct_left[0] = 1;
    distinct_right[n - 1] = 1;
    // set<char> distLeft, distRight;
    visited.clear();
    visited.resize(26, false);
    visited[s[0] - 'a'] = true;
    for (int i = 1; i < n; i++)
    {
        if (visited[s[i] - 'a'] == false)
        {
            distinct_left[i] = 1 + distinct_left[i - 1];
            visited[s[i] - 'a'] = true;
        }
        else
            distinct_left[i] = distinct_left[i - 1];
        cout << distinct_left[i] << " ";
    }
    cout << endl;
    visited.clear();
    visited.resize(26, false);
    visited[s[n - 1] - 'a'] = true;
    for (int i = n - 2; i >= 0; i--)
    {
        if (visited[s[i] - 'a'] == false)
        {
            distinct_right[i] = 1 + distinct_right[i + 1];
            visited[s[i] - 'a'] = true;
        }
        else
            distinct_right[i] = distinct_right[i + 1];
        cout << distinct_right[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < n; i++)
    {
        if (distinct_left[i - 1] == distinct_right[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}