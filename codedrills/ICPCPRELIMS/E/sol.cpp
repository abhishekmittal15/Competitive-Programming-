// M???U
// U???U
// M???M
// // U???M 

#include<iostream>
#include<string>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.length();
        bool m_came = false;
        bool flag = false;
        for (int i = 0; i < n;i++){
            if(s[i]=='M')
                m_came = true;
            if(s[i]=='U' && m_came){
                flag = true;
                break;
            }
        }
        if(flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}