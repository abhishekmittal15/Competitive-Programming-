#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& a,int m){
    int n=a.size();
    for (int i= n - 1; i >= 0;i--){
        if(a[i]==m)
            return i + 1;
    }
    return -1;
}
signed main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for (int i = 0;i<n;i++){
        cin>>a[i];
    }
    int ans=solve(a,m);
    cout << ans << endl;
    return 0;
}