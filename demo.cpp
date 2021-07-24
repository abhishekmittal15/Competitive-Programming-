#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long int 
signed main(){
    vector<int> a{1, 2, 3, 4, 5, 6};
    auto it = lower_bound(a.begin(), a.end(), 5);
    int ans = it - a.begin();
    cout << a[ans] << endl;
    return 0;
}