#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
string cyclic_shift(string s,int c,int n){
    int idx = c;
    string ans = "";
    while(idx<(n+c)){
        ans += (s[idx]);
        idx++;
    }
    return ans;
}
bool check(string s,string t){
    int n = s.length();
    for (int i = 0;i<n;i++){
        if(s[i]==t[i])
            return true;
    }
    return false;
}
signed main(){
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests;t++){
        string s,ans;
        cin>>s;
        int n = s.length();
        string temp = s + s;
        bool flag = false;
        for (int i = 1;i<n;i++){
            ans = cyclic_shift(temp, i,n);
            if(check(ans,s)==false){
                flag = true;
                break;
            }
        }
        if(flag==false)
            ans = "IMPOSSIBLE";
        cout << "Case #" << t << ": " << ans << endl;
    }
}