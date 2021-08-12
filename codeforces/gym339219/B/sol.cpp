#include<iostream>
#include<vector>
using namespace std;
// #define int long long int 
signed main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin >> s;
        int n = s.length();
        vector<int> map(3,-1);
        if(s[0]==s[n-1]){
            cout << "No" << endl;
            continue;
        }
        map[s[0] - 'A'] = 1;
        map[s[n-1] - 'A'] = 0;
        int sum = (1 << (int)(s[0] - 'A')) + (1 << (int)(s[n - 1] - 'A'));
        char var = 'A';
        if (sum == 3)
            var = 'C';
        if(sum==5)
            var = 'B';
        map[var - 'A'] = 1;
        int cnt = 0;
        bool flag = true;
        for (int i = 0; i < n;i++){
            if(map[s[i]-'A']==1)
                cnt++;
            else
                cnt--;
            if(cnt<0){
                flag = false;
                break;
            }
        }
        if(cnt!=0)
            flag = false;
        map[var - 'A'] = 0;
        cnt = 0;
        bool flag2 = true;
        for (int i = 0; i < n; i++)
        {
            if (map[s[i] - 'A'] == 1)
                cnt++;
            else
                cnt--;
            if (cnt < 0)
            {
                flag2 = false;
                break;
            }
        }
        if (cnt != 0)
            flag2 = false;
        if(flag| flag2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}