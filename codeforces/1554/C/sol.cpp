#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    int maxBit = 31;
    while(t--){
        int n,m;
        cin>>n>>m;
        int ans = 0;
        if(m<n){
            cout << ans << endl;
            continue;
        }
        for (int i = 0; i <= maxBit;i++){
            if((n&(1<<i))==0){
                ans +=( 1 << i);
                if((n+(1<<i))>m)
                    break;
                n += (1 << i);
                cout << i << " " << n << endl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}