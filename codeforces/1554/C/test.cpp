#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
signed main(){
    int n,m;
    cin>>n>>m;
    vector<int> a;
    for(int i=0;i<=m;i++)
        a.push_back(n^i);
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}