#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    string s;
    cin>>s;
    int n = s.length();
    int k;
    cin>>k;
    k--;
    int ans = 0;
    for (int i = 0; i < n;i++){
        int cur = s[i] - 'a' + 1;
        while(cur>0){
            ans += cur % 10;
            cur /= 10;
        }
    }
    while(k>0){
        int temp = ans;
        ans = 0;
        while(temp>0){
            ans += temp % 10;
            temp /= 10;
        }
        k--;
    }
    cout << ans << endl;
}