#include<iostream>
using namespace std;
#define int long long int 
string solve(string order,string str){
    string result = "";
    bool present_in_order[26];
    for (int i = 0; i < 26;i++)
        present_in_order[i] = false;
    for (int i = 0; i < order.length();i++){
        for (int j = 0; j < str.length();j++){
            if(str[j]==order[i]){
                result += order[i];
                present_in_order[order[i] - 'a'] = true;
            }
        }
    }
    for (int i = 0; i < str.length();i++)
        if(present_in_order[str[i]-'a']==false)
            result += str[i];
    return result;
}
signed main(){
    string order, str;
    cin >> order >> str;
    string ans = solve(order, str);
    cout << ans << endl;
    return 0;
}