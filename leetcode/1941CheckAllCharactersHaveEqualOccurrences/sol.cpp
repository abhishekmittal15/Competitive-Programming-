#include<iostream>
#define int long long int 
using namespace std;
signed main(){
    string s;
    cin>>s;
    bool ans = true;
    int prev = 0;
    int n = s.length();
    int freq[26];
    for (int i = 0; i < 26;i++)
        freq[i] = 0;
    for (int i = 0; i < n; i++)
        freq[s[i] - 'a']++;
    for (int i = 0; i < 26;i++)
        if(freq[i]>0){
            if(prev>0)
                ans = ans & (freq[i] == prev);
            prev = freq[i];
        }
    cout << ans << endl;
}