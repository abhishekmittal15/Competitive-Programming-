#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int, q;
    cin >> n >> q;
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n;i++){
        cin >> parent;
        g[parent].push_back(i);
    }
    while(q--){
        int u,d;
        cin >> u >> d;
        cout << query(u, d) << endl;
    }
    return 0;
}