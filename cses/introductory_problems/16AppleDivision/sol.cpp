#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n,sum=0;
    cin>>n;
    vector<int> a(n);
    for (int i = 0;i<n;i++)
        cin >> a[i], sum += a[i];
    int masks=1ll<<n;
    int ans = 1e10;
    for (int mask = 0; mask < masks;mask++){
        int cur_sum = 0;
        for (int i = 0;i<n;i++)
            if(mask&(1ll<<i))
                cur_sum += a[i];
        ans = min(ans, abs(sum - 2*cur_sum));
    }
    cout << ans << endl;
    return 0;
}