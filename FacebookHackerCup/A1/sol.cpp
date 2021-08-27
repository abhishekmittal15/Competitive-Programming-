#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests;t++){
        int ans = 0;
        string s;
        cin>>s;
        int n = s.length();
        int all_vowels = 0;
        int all_consonants = 0;
        int max_same_vowel = 0, max_same_consonant = 0;
        char v, c;
        vector<int> cnt(26, 0);
        for (int i = 0;i<n;i++){
            cnt[s[i] - 'A']++;
            if (s[i] == 'A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U'){
                if(cnt[s[i]-'A']>max_same_vowel)
                    max_same_vowel = max(max_same_vowel, cnt[s[i] - 'A']++), v = s[i];
            }
            else{
                if (cnt[s[i] - 'A'] > max_same_consonant)
                    max_same_consonant = max(max_same_consonant, cnt[s[i] - 'A']++), c = s[i];
            }
        }
        for (int i = 0; i < n;i++){
            if (s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U'){
                if(s[i]!=v)
                    all_vowels+=2;
            }
            else
                all_vowels++;
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U'){
                all_consonants++;
            }
            else if (s[i] != c)
                all_consonants += 2;
        }
        ans = min(all_vowels, all_consonants);
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}