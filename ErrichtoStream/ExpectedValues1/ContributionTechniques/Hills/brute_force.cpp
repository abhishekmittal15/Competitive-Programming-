#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
#define double long double 
#define one 1ll
signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    int ans = 0;
    for (int j = 1; j < (n - 1);j++){
        int cntleft = 0;
        int cntright = 0;
        for (int i = 0; i < j;i++){
            cntleft += (a[i] < a[j]);
        }
        for (int i = j+1; i < n; i++)
        {
            cntright += (a[i] < a[j]);
        }
        ans += (cntright * cntleft);
    }
    cout << ans << endl;
}