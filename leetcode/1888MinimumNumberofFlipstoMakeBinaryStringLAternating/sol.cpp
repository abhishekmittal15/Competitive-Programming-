#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(string s){
    int n = s.length();
    string temp=s;
    for (int i = 0;i<n;i++)
        temp.push_back(s[i]);
    vector<int> prefix(2 * n+1, 0);
    bool cur = 0;
    for (int i = 0; i < 2 * n;i++){
        prefix[i + 1] = prefix[i] + ((temp[i] - '0') ^ (cur));
        cur = 1 - cur;
    }
    int inf = 1e9;
    int ans = inf;
    for (int i = 0; i < n; i++)
    {
        int start = i + 1;
        int end = start + n - 1;
        int sol = prefix[end] - prefix[start - 1];
        ans = min(ans, min(sol, n - sol));
    }
    return ans;
}
signed main(){
    string s;
    cin>>s;
    int ans = solve(s);
    cout << "Answer : " << ans << endl;
    return 0;
}