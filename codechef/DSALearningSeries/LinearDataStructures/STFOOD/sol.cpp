#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        int ans = -1;
        for (int i = 0; i < n;i++){
            int stores, people, price;
            cin >> stores >> people >> price;
            int profit = (people / (stores + 1)) * price;
            ans = max(ans, profit);
        }
        cout << ans << endl;
    }
    return 0;
}