#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& a){
    int n = a.size();
    int ans = 0, cur = 0;
    for (int i = 0; i < n;i++){
        cur = cur + a[i];
        if(ans<cur)
            cur = ans;
        if(cur<0)
            cur = 0;
    }
    return ans;
}
signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];
    int ans = solve(a);
    cout << "Answer : " << ans << endl;
    return 0;
}