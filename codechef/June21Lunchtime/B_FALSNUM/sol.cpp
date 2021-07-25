#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        if(s[0]=='1'){
            cout << 1 << 0;
            for (int i = 1; i < n;i++)
                cout << s[i];
        }
        else{
            cout << 1;
            cout << s;
        }
        cout << endl;
    }
    return 0;
}