#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
#define a 1 
#define b 2
signed main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int ans = 10, loser = b, winner = a,sa=0,sb=0,ua=0,ub=0;
        for (int i = 0; i < 10;i++){
            if(i%2==0){
                if(s[i]=='1')
                    sa++;
                if(s[i]=='?')
                    ua++;
            }
            if(i%2==1){
                if (s[i] == '1')
                    sb++;
                if(s[i]=='?')
                    ub++;
            }
            // if(sa<sb){
            //     loser = a;
            //     winner = b;
            // }
            // if(sa>sb){
            //     loser = b;
            //     winner = a;
            // }
            // if(sa==sb){
            //     loser = 0;
            //     winner = 0;
            // }
            int rem_chances_a = 4 - i/2;
            int rem_chances_b = rem_chances_a+1;
            if(i%2)
                rem_chances_b--;
            // cout <<i+1<<" "<< sa << " " << sb << " " << ua << " " << ub << " " << rem_chances_a <<" "<<rem_chances_b<< endl;
            if(rem_chances_a+sa<sb+ub || rem_chances_b+sb<sa+ua){
                ans=i+1;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}