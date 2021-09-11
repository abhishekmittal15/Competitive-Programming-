#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int n,k,z;
vector<int> a;
int solve(){
    vector<int> prefix(n + 1);
    prefix[0] = 0;
    int mx = 0;
    for (int i = 1; i <=n ;i++){
        // cout<<a[i-1]<<" ";
        prefix[i] = prefix[i - 1] + a[i - 1];
        if(i==1)
            continue;
        int pair_sum = a[i] + a[i - 1];
        int rem = k - (i - 1);
        int score = prefix[i] + (min(rem, z) * pair_sum);
        if(z==(rem+1))
            score += a[i - 1];
        mx = max(mx, score);
        // cout << i << " " << score << endl;
    }
    return mx;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k>>z;
        a.clear();
        a.resize(n);
        for (int i = 0; i < n;i++)
            cin>>a[i];
        cout<<solve()<<endl;
    }
    return 0;
}