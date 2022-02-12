#include<iostream>

using namespace std;
#define int long long int 

signed main(){
    string s;
    cin >> s;
    int a,b;
    cin >> a >> b;
    char temp = s[a - 1];
    s[a - 1] = s[b - 1];
    s[b - 1] = temp;
    cout << s << endl;
    return 0;
}