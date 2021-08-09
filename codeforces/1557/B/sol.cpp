#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for (int i = 0;i<n;i++)
            cin >> a[i];
        int cnt = 1;
        for (int i = 1; i < n;i++){
            if(a[i]<a[i-1])
                cnt++;
        }
        // cout << cnt << endl;
        if(cnt<=k)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}