#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    string s, ans;
    cin>>s;
    if(s[0]=='?'){
        ans+= ((s[1] - '0' >= 0 && s[1] - '0' <= 3) || s[1] == '?')?'2' : '1';
    }
    else
        ans += s[0];
    if(s[1]=='?'){
        ans+= (ans[0] - '0' == 1 || ans[0] - '0' == 0) ? '9' : '3';
    }
    else
        ans += s[1];
    ans+= ':';
    if(s[3]=='?'){
        ans+= '5';
    }
    else
        ans += s[3];
    if(s[4]=='?')
        ans+= '9';
    else
        ans += s[4];
    cout << ans << endl;
    return 0;
}