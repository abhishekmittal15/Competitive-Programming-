#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main(){
    int t;
    cin>>t;
    for(int c=1;c<=t;c++){
        int n;
        cin>>n;
        int k;
        cin>>k;
        string s;
        cin>>s;
        int cur_score=0;
        for(int i=0;i<n/2;i++)
            cur_score+=(s[i]!=s[n-i-1]);
        cout<<"Case #"<<c<<": "<<abs(cur_score-k)<<endl;
    }
    return 0;
} 