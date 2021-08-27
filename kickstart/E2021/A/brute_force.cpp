#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    for (int i = 1; i <= t;i++){
        string s;
        cin>>s;
        string temp = s;
        int n = s.length();
        bool flag;
        sort(s.begin(), s.end());
        do{
            flag = true;
            for (int j = 0; j < n;j++){
                if(s[j]==temp[j])
                    flag = false;
            }
            if(flag)
                break;
        } while (next_permutation(s.begin(), s.end()));
        cout << "Case #" << i << ": ";
        if(flag)
            cout << s << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
}