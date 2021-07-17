#include<iostream>
using namespace std;
#define int long long int
int inf = 1000 * 1000 * 1000 + 7;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,prev=inf,ans=0,cur_min=inf;
        cin >> n;
        for (int i = 0,coins; i < n;i++){
            cin >> coins;
            if(coins<prev){
                ans += coins;
                cur_min = coins;
                prev = coins;
            }
            else
                ans += cur_min;
        }
        cout << ans << endl;
    }
    return 0;
}