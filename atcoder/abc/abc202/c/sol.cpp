#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin >> n;
    vector<int> a(n+1,0),b(n+1,0), c(n+1,0),temp(n+1,0);
    for (int i = 0,x; i < n;i++)
        cin >> x, a[x]++;
    for (int i = 0; i < n;i++)
        cin >> b[i];
    for (int i = 0; i < n;i++)
        cin >> c[i];
    for (int i = 0; i < n;i++){
        temp[b[c[i]-1]]++;
    }
    int ans = 0;
    // for (int i = 1; i <= n;i++)
    //     cout << a[i] << " " << temp[i] << endl;
    for (int i = 1; i <= n; i++)
        ans += (a[i] * temp[i]);
    cout << ans << endl;
    return 0;
}   