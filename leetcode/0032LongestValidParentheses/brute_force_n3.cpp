#include<iostream>
using namespace std;
#define int long long int 
bool valid(string s){
    int n = s.length();
    int open = 0;
    for (int i = 0; i < n;i++){
        if(s[i]=='(')
            open++;
        if(s[i]==')')
            open--;
        if(open<0)
            return false;
    }
    return open == 0;
}
int solve(string s){
    int n = s.length();
    int ans = -1;
    for (int start = 0; start < n - 1;start++){
        for (int end = start + 1; end < n;end++){
            string temp;
            for (int i = start; i <= end;i++){
                temp.push_back(s[i]);
            }
            if(valid(temp))
                ans = max(ans, end - start + 1);
        }
    }
    return ans;
}
signed main(){
    string s;
    cin >> s;
    int answer = solve(s);
    cout << "Answer : " << answer << endl;
    return 0;
}