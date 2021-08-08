#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int
signed main(){
    int n;
    cin>>n;
    vector<pair<int,int>> a(n+1);
    a[0] = {0, 0};
    for (int i = 1; i <=n;i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    // for (int i = 1;i<=n;i++)
    //     cout << a[i].second << " " << a[i].first << endl;
        cout << a[n - 1].second << endl;
        return 0;
}