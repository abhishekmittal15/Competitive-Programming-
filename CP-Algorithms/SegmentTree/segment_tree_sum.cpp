#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
void build(vector<int>& seg,vector<int>& a,int )
signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> seg(4 * n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    build(seg, a, 0, 0, n - 1);

}