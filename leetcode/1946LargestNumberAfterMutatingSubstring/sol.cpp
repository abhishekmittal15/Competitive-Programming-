#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
string solve(string s,vector<int>& change){
    int leftidx = 0;
    int n = s.length();
    string ans = s;
    for (leftidx = 0; leftidx < n;leftidx++)
        if((s[leftidx]-'0')<change[s[leftidx]-'0'])
            break;
    for (int i = leftidx; i < n;i++){
        if ((s[i]-'0') > change[s[i]-'0'])
            break;
        ans[i] = change[s[i] - '0'] + '0';
    }
    return ans;
}
signed main(){
    string num;
    cin >> num;
    vector<int> change(10);
    for (int i = 0; i <10;i++){
        int a;
        cin >> a;
        change[i] = a;
    }
    string ans = solve(num, change);
    cout << ans << endl;
    return 0;
}