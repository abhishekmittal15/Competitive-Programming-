#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n;i++){
        int parent;
        cin >> parent;
        g[parent].push_back(i);
    }
    while(q--){
        
    }
}