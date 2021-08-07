#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    int max_n = 1e6 + 5;
    vector<int> pref(max_n,0);
    for (int i = 1; i < max_n;i++){
        pref[i] = pref[i - 1] + i;
    }
    for (int i = 1; i <= t; i++)
    {
        int g;
        int ans = 0;
        cin >> g;
        
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}