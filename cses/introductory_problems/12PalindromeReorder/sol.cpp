#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    string s;
    cin>>s;
    int cnt[26]={0};
    for(int i=0;i<s.length();i++){
        cnt[s[i]-'A']++;
    }
    int odd_cnt = 0;
    for (int i = 0; i < 26;i++){
        if(cnt[i]%2)
            odd_cnt++;
    }
    if(odd_cnt>1)
        cout << "NO SOLUTION" << endl;
    else{
        for (int i = 0; i < 26;i++){
            if(cnt[i]%2==0)
            {int desired = cnt[i] / 2;
            while(desired--){
                cout << (char)(i + 'A');
            }}
        }
        for (int i = 0; i < 26;i++){
            if(cnt[i]%2){
                int desired = cnt[i];
                while(desired--)
                    cout << (char)(i + 'A');
            }
        }
        for (int i = 25; i >= 0;i--){
            if(cnt[i]%2==0){
                int desired = cnt[i] / 2;
                while (desired--)
                {
                    cout << (char)(i + 'A');
                }
            }
        }
    }
    return 0;
}