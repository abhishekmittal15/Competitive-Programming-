#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
bool valid(string s){
    vector<char> brackets;
    int n = s.length();
    for (int i = 0; i < n;i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            brackets.push_back(s[i]);
        }
        else{
            if(brackets.empty())
                return false;
            if ((s[i] == ')' && brackets.back() == '(') || (s[i] == ']' && brackets.back() == '[') || (s[i] == '}' && brackets.back() == '{'))
                brackets.pop_back();
            else
                return false;
        }
    }
    return brackets.empty();
}
signed main(){
    string s;
    cin >> s;
    string ans = valid(s) ? "Yes" : "No";
    cout << ans << endl;
    return 0;
}