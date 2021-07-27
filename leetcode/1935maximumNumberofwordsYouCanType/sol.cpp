#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int solve(string text,string brokenLetters){
    int n = text.length();
    int ans = 0;
    bool new_word = true;
    for (int i = 0; i < n; i++)
    {
        if (text[i] == ' ')
        {
            if (new_word)
                ans++;
            new_word = true;
            continue;
        }
        if (new_word)
        {
            for (int j = 0; j < brokenLetters.length(); j++)
                if (text[i] == brokenLetters[j])
                    new_word = false;
        }
    }
    if (new_word)
        ans++;
    return ans;
}
signed main(){
    string text, brokenLetters;
    cin >> text >> brokenLetters;
    int ans = solve(text, brokenLetters);
    cout << "Answer : " << ans << endl;
    return 0;
}