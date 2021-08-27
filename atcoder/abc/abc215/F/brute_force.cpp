#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
struct pt{
    int x, y;
};
signed main(){
    int n;
    cin>>n;
    vector<pt> a(n);
    int ans = 0;
    for (int i = 0;i<n;i++){
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < n;i++){
        for (int j = i + 1; j < n;j++){
            ans = max(ans, min(abs(a[i].x - a[j].x), abs(a[i].y - a[j].y)));
        }
    }
    cout<<ans<<endl;
    return 0;
}