#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> dpsq(n),dpnsq(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    dpsq[0] = a[0] ^ 2;
    dpnsq[0] = a[0];
    for (int i = 1; i < n;i++){
        dpsq[i] = max(dpsq[i - 1] + a[i], max(dpnsq[i - 1] + a[i] ^ 2, a[i] ^ 2));
        dpnsq[i] = max(dpnsq[i - 1] + a[i], a[i]);
    }
    cout << dpsq[n - 1] << endl;
    return 0;
}