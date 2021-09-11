#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
signed main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for (int i = 0; i < n;i++)
        cin >> a[i];
    for (int i = 0; i < m;i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int max_correct = a.back();
    int min_wrong=b[0];
    int half_time=a[0];
    int ans = max_correct;
    if(half_time*2>ans){
        max_correct = half_time * 2;
        ans = max_correct;
    }
    if(min_wrong<=max_correct)
        ans = -1;
    cout << ans << endl;
    return 0;
}
