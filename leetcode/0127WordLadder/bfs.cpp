#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define int long long int 
int solve(string beginWord,string endWord,vector<string>& wordList){
    int n = wordList.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n;i++){
        if(wordList[i]==beginWord)
            visited[i] = true;
    }
    queue<string> q;
    q.push(beginWord);
    int ans = 1;
    while(q.empty()==false){
        int n = q.size();
        for (int i = 0; i < n;i++){
            string current = q.front();
            cout << current << " ";
            q.pop();
            if(current==endWord)
                return ans;
            for (int j = 0; j < wordList.size();j++){
                string nextword = wordList[j];
                int diff = 0;
                for (int k = 0; k < nextword.length();k++){
                    if(current[k]!=nextword[k])
                        diff++;
                }
                if(diff==1 && visited[j]==false){
                    visited[j] = true;
                    q.push(nextword);
                }
            }
        }
        cout << endl;
        ans++;
    }
    return 0;
}
signed main()
{
    string beginWord, endWord;
    cin >> beginWord >> endWord;
    int n;
    cin >> n;
    vector<string> wordList(n);
    for (int i = 0; i < n; i++)
        cin >> wordList[i];
    int answer = solve(beginWord, endWord, wordList);
    cout << "Answer : " << answer << endl;
    return 0;
}