#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int countPalindromicSubsequence(string s)
{
    int ans = 0;
    vector<bool> visited(26, false);
    vector<bool> visited2;
    for (int i = 0; i < s.length(); i++)
    {
        if (visited[s[i] - 'a'] == false)
        {
            int cnt = 0;
            visited2.clear();
            visited2.resize(26, false);
            int last = -1;
            for (int j = s.length() - 1; j > i;j--){
                if(s[j]==s[i]){
                    last = j;
                    break;
                }
            }
            for (int j = i + 1; j < last;j++){
                if(visited2[s[j]-'a']==false){
                    cnt++;
                    visited2[s[j] - 'a'] = true;
                }
            }
            ans += cnt;
            visited[s[i] - 'a'] = true;
        }
    }
    return ans;
}
signed main(){
    string s;
    cin>>s;
    int ans = countPalindromicSubsequence(s);
    cout<< "Answer : " << ans << endl;
    return 0;
}