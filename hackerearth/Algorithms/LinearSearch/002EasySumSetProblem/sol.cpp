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
    int m;
    cin>>m;
    vector<int> c(m);
    for (int i = 0;i<m;i++){
        cin >> c[i];
    }
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());
    int mx=c.back()-a.back();
    int mn = c[0] - a[0];
    for (int i = mn; i <= mx;i++){
        bool flag = false;
        for (int j = 0;j<n;j++){
            int cur_sum = i + a[j];
            for (int k = 0; k < m;k++){
                if(cur_sum==c[k])
                    flag = true;
            }
        }
        if(flag)
            cout << i << " ";
    }
    cout << endl;
    return 0;
}