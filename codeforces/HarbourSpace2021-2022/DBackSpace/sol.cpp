#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    while(t--){
        string s, t;
        cin >> s >> t;
        int n = s.length();
        vector<char> even, odd;
        for (int i = n - 1; i >= 0;i--){
            if((n-i-1)%2)
                odd.push_back[s[i]];
            else
                even.push_back(s[i]);
        }
        reverse(even.begin(), even.end());
        reverse(odd.begin(), odd.end());
        int m = t.length();
        int ptr = 0;
        int even_ptr = even.size();
        int odd_ptr = odd.size();
        for (int i = m - 1; i >= 0;i--){
            if(ptr==0)
                for (; even_ptr >= 0;even_ptr--)
                    if(even[even_ptr]==t[i]){
                        ptr = 1;
                        
                    }
        }
    }
}