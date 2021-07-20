#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n,m,ans=0;
    cin >> n >> m;
    vector<int> price(m+1,0);
    for (int i = 0,pri,box; i < n;i++){
        cin >> pri >> box;
        price[box] = max(price[box], pri);
    }
    for (int i = 1; i <=m;i++)
        ans += price[i];
    cout << ans << endl;
    return 0;
}