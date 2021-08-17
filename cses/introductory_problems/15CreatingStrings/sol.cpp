#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    vector<int> fac(10);
    vector<int> cnt(26);
    fac[0] = 1;
    for (int i = 1; i < 10;i++)
        fac[i] = fac[i - 1] * i;
    for (int i = 0;i<s.length();i++){
        cnt[s[i] - 'a']++;
    }
    int moves=fac[s.length()];
    for (int i = 0;i<26;i++){
        moves /= fac[cnt[i]];
    }
    cout << moves << endl;
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}