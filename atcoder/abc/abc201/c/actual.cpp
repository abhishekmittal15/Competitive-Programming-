#include<bits/stdc++.h>
using namespace std;
int main(){
    string S; cin >> S;
    int ans = 0;
    for(int i=0; i<=9999; i++){
        vector<bool> flag(10);
        int X = i;
        for(int j=0; j<4; j++){
            flag[X%10] = true;
            X /= 10;
        }
        bool flag2 = true;
        for(int j=0; j<10; j++){
            if(S[j]=='o' && !flag[j]) flag2 = false;
            if(S[j]=='x' && flag[j]) flag2 = false;
        }
        ans += flag2;
    }
    cout << ans << endl;
}