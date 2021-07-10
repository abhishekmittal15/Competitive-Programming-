#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin >> t;
    while(t--){
        int n, k,max_p=30,ans=0;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n;i++)
            cin >> a[i];
        for (int p = 0; p <= max_p;p++){
            int cnt = 0;
            for (int i = 0;i<n;i++){
                if(a[i]&(1<<p))
                    cnt++;
            }
            ans += (cnt / k + (cnt % k != 0));
        }
        cout << ans << endl;
    }
    return 0;
}
