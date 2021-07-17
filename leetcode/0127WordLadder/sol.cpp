#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int dfs(string word,string endWord,vector<string>& wordList,vector<int>& cnt){
    if(word==endWord){
        return 1;
    }
    int n = wordList.size(),ans=5005;
    for (int i = 0; i < n;i++){
        string currentWord = wordList[i];
        int diff = 0;
        for (int j = 0; j < currentWord.length();j++){
            if(currentWord[j]!=word[j])
                diff++;
        }
        if(diff==1){
            if(cnt[i]==-1){
                cnt[i] = 5005;
                cnt[i] = dfs(currentWord, endWord, wordList,cnt);
            }
            ans = min(ans, cnt[i]);
        }
    }
    return ans + 1;
}
int solve(string beginWord,string endWord,vector<string>& wordList){
    for (auto it = wordList.begin(); it != wordList.end();it++){
        if(*it==beginWord){
            wordList.erase(it);
            break;
        }
    }
    vector<int> cnt(wordList.size(), -1);
    int ans = dfs(beginWord, endWord, wordList, cnt);
    if(ans>5000)
        ans = 0;
    return ans;
}
signed main(){
    string beginWord, endWord;
    cin >> beginWord >> endWord;
    int n;
    cin >> n;
    vector<string> wordList(n);
    for (int i = 0; i < n;i++)
        cin >> wordList[i];
    int answer = solve(beginWord, endWord, wordList);
    cout << "Answer : " << answer << endl;
    return 0;
}