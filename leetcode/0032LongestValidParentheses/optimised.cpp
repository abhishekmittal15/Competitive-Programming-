#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(string s){
    int n = s.length();
    int ans = -1;
    vector<int> stack{-1};
    for (int i = 0; i < n;i++){
        if(s[i]=='(')
            stack.push_back(i);
        else if(stack.size()==1)
            stack[0] = i;
        else{
            stack.pop_back();
            ans = max(ans, i - stack.back());
        }
    }
    return ans;
}
signed main(){
    string s;
    cin>>s;
    int answer = solve(s);
    cout << "Answer : " << answer << endl;
    return 0;
}