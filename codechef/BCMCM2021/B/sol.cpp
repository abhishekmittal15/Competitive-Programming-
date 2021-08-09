#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
        int num;
        cin>>num;
        int index = lower_bound(a.begin(), a.end(), num) - a.begin();
        cout << index << endl;
        return 0;
}