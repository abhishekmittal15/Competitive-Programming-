#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    string s;
    cin>>s;
    int cnt = 1;
    int ans = 0;
    for (int i = 1;i<s.length();i++){
        if(s[i]==s[i-1])
            cnt++;
        else
            ans = max(ans, cnt), cnt = 1;
    }
    ans = max(ans, cnt);
    cout << ans << endl;
}