#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int solve(string s){
    int n = s.length();
    int ans = 0;
    vector<int> cnt;
    for (int i = 0;i<n;i++){
        for (int j = i ; j < n;j++){
            cnt.clear();
            cnt.resize(10,0);
            int odd = 0;
            for (int start = i; start <= j;start++)
                cnt[s[start] - 'a']++;
            for (int i = 0; i < 10;i++)  
                if(cnt[i]%2)
                    odd++;
            if(odd<=1)
                ans++;
        }
    }
    return ans;
}
signed main(){
    string s;
    cin >> s;
    int ans = solve(s);
    cout << "Answer : " << ans << endl;
    return 0;
}