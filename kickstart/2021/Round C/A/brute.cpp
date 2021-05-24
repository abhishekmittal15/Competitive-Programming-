#include<bits/stdc++.h>
using namespace std;
bool checklex(string s1,string s2){
    return s1<s2;
}
bool checkpal(string s){
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]!=s[n-i-1])
            return false;
    }
    return true;
}
int f(int pos,int n,int k,string s,string test){
    int cnt=0;
    if(pos==n){
        bool flag = checklex(test, s) & checkpal(test);
        if(flag){
            // cout << test << endl;
            return 1;
        }
        else
            return 0;
    }
    for(int i=0;i<k;i++){
        string temp=test+(char)('a'+i);
        cnt+=f(pos+1,n,k,s,temp);
    }
    return cnt;
}
int main(){
    int t = 625;
    for (int test = 1; test <= t; test++)
    {
        int n=4,k=5;
        // cin>>n>>k;
        string s;
        cin>>s;
        int ans=f(0,n,k,s,"");
        cout << "Case #" << test << ": " << ans << endl;
    }
    return 0;
}