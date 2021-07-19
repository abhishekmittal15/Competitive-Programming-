#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n, k, ans = 32;
    cin>>n>>k;
    vector<string> str(n);
    for (int i = 0; i < n;i++){
        cin >> str[i];
    }
    for (int i = 0; i < n;i++){
        for (int j = i + 1; j < n;j++){
            int diff = 0;
            string s1 = str[i];
            string s2 = str[j];
            for (int ptr = 0; ptr < k;ptr++){
                if(s1[ptr]!=s2[ptr])
                    diff++;
            }
            ans = min(ans, diff);
        }
    }
    cout << ans << endl;
    return 0;
}