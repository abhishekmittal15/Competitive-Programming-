#include<iostream>
using namespace std;
#define int long long int 
#define playera 0
#define playerb 1
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,a=0,b=0;
        cin >> n;
        int total = 2 * n;
        int ans = total;
        string s;
        cin >> s;
        for (int i = 1; i <=total;i++){
            if(s[i-1]=='1'){
                if(i%2)
                    a++;
                else
                    b++;
            }
            int lefta = (total - i) / 2;
            int leftb = (total-i+1)/2;
            int loser = -1;
            if(a<b)
                loser = playera;
            else if(a>b)
                loser = playerb;
            // cout << lefta << " " << leftb << " " << a << " " << b << " " << loser << endl;
            if(loser>=0){
                if(loser==playera && (a+lefta)<b){
                    ans = i;
                    break;
                }
                if(loser==playerb && (b+leftb)<a){
                    ans = i;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}