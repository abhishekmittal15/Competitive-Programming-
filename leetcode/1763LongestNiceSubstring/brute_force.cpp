#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
string solve(string s){
    int ans = 0;
    vector<bool> low;
    vector<bool> up;
    int n = s.length();
    for (int left = 0; left < n;left++){
        for (int right = left+1; right < n;right++){
            low.resize(26, false);
            up.resize(26, false);
            for (int ptr = left; ptr <= right;ptr++){
                
            }
        }
    }
}
signed main(){
    string s;
    cin >> s;
    string ans = solve(s);
    cout << "Answer : " << ans << endl;
    return 0;
}