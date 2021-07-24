#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(string s){
    int n = s.length();
    vector<bool> visited(26, false);
    int ans = 0;
    vector<int> distinct_left(n,0);
    vector<int> distinct_right(n,0);
    distinct_left[0] = 1;
    distinct_right[n-1] = 1;
    visited[s[0] - 'a'] = true;
    for (int i = 1; i < n;i++){
        if(visited[s[i]-'a']==false){
            distinct_left[i]=1+distinct_left[i-1];
            visited[s[i] - 'a'] = true;
        }
        else
            distinct_left[i] = distinct_left[i - 1];
    }
    visited.clear();
    visited.resize(26, false);
    visited[s[n-1] - 'a'] = true;
    for (int i = n-2; i>=0; i--)
    {
        if (visited[s[i] - 'a'] == false)
        {
            distinct_right[i] = 1 + distinct_right[i + 1];
            visited[s[i] - 'a'] = true;
        }
        else
            distinct_right[i] = distinct_right[i + 1];
    }
    for (int i = 1; i < n;i++){
        if(distinct_left[i-1]==distinct_right[i])
            ans++;
    }
    return ans;
}
signed main(){
    string s;
    cin >> s;
    int ans = solve(s);
    cout << "Answer : " << ans << endl;
    return 0;
}