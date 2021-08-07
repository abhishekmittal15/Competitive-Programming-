#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n;i++)
        cin >> a[i] >> b[i];
    cout << (a == b) << endl;
    return 0;
}