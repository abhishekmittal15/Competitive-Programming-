#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    while(t--){
        string s,ans="Success";
        cin >> s;
        int n = s.length();
        if(s[0]!='<' || s[1]!='/' || s[n-1]!='>')
            ans = "Error";
        else{
            for (int i = 2; i < n-1;i++){
                int ch = s[i] - 'a';
                int dig = s[i] - '0';
                if((ch>=0 && ch<=25) || (dig>=0 && dig<=9))
                    continue;
                ans = "Error";
                break;
            }
            if(n==3)
                ans = "Error";
        }
        cout << ans << endl;
    }
    return 0;
}