#include<iostream>
using namespace std;
#define int long long int 
int solve(string s){
    int n = s.length();
    int ans = 0;
    for (int left = 0,right = 2; right < n;left++,right++){
        if(s[left]!= s[left+1] && s[left]!=s[right] && s[left+1]!=s[right])
            ans++;
    }
    return ans;
}
signed main(){
    string s;
    cin>>s;
    int ans = solve(s);
    cout << "Answer : " << ans << endl;
    return 0;
}