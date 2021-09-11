#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin >> n;
    vector<int> p(n + 1), q(n + 1);
    for (int i = 1; i <= n;i++){
        cin >> p[i];
        q[p[i]] = i;
    }
    for (int i = 1; i <= n;i++)
        cout << q[i] << " ";
    return 0;
}