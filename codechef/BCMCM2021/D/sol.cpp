// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// #define int long long int 
// signed main(){
//     int n;
//     cin>>n;
//     int ans = 0;
//     vector<int> a(n);
//     for (int i = 0; i < n;i++)
//         cin >> a[i];
//     sort(a.begin(), a.end());
//     int median = a[n / 2];
//     for (int i = 0; i < n;i++){
//         ans += abs(a[i] - median);
//     }
//     if(n==1){
//         cout << 0 << endl;
//         return 0;
//     }
//     median = a[n / 2 - 1];
//     int ans2 = 0;
//     for (int i =0; i < n;i++)
//         ans2 += abs(a[i] - median);
//     ans = min(ans, ans2);
//     cout << ans << endl;
//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long int
signed main()
{
    int n;
    cin >> n;
    int ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    int mid = a[n / 2];
    int mid1 = a[(n / 2) - 1];
    int res1 = 0, res2 = 0;
    for (int i = 0; i < n; i++)
    {
        res1 = res1 + abs(a[i] - mid);
        res2 = res2 + abs(a[i] - mid1);
    }
    ans = min(res1, res2);
    cout << ans << endl;
    return 0;
}