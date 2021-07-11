#include<iostream>
using namespace std;
#define int long long int 
void solve(int *a,int n){
    dfs(0, a, n);
}
signed main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    solve(a, n);
}