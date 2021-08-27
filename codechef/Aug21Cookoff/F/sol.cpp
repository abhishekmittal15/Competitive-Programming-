#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int f(int l,int r,vector<int>& a,int k,int x){
    int choice1=a[l]+f(l+1,r,a,k,x);
    int choice2 = a[r] + f(l, r - 1, a, k, x);
    int choice3 = x + f(l + 1, r - 1, a, k - 1, x);
    return min(choice1, choice2, choice3);
}
int solve(int n,int k,int x,vector<int>& a){
    int l=0;
    int r = n - 1;
    return f(l, r, a, k, x);
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,x;
        cin>>n>>k>>x;
        vector<int> a(n);
        for (int i = 0; i < n;i++){
            cin >> a[i];
        }
        int ans = solve(n, k, x, a);
        cout<<ans<<endl;
    }
    return 0;
}