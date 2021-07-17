#include<iostream>
#include<map>
using namespace std;
#define int long long int
int mod = 1000 * 1000 * 1000 + 7;
int solve(string s,string t){
    map<string, int> cnt;
    cnt[""] = 1;
    int n = s.length();
    int m = t.length();
    for (int i = 0; i < n;i++){
        char current = s[i];
        string temp = t;
        for (int j = m-1; j >=0;j--){
            if(current==temp.back()){
                string temp2 = temp;
                temp2.pop_back();
                cnt[temp] = cnt[temp]+cnt[temp2];
                if(cnt[temp]>=mod)
                    cnt[temp] -= mod;
            }
            temp.pop_back();
        }
    }
    return cnt[t];
}
signed main(){
    string s,t;
    cin >> s >> t;
    int answer = solve(s, t);
    cout << "Answer : " << answer << endl;
    return 0;
}