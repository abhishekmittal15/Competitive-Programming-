#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
int solve(vector<int>& a){
    int n = a.size();
    sort(a.begin(), a.end());
    int ans = 0, cost = 0;
    for (int i = 1; i < n;i++){
        if(a[i]!=a[i-1])
            cost++;
        ans += cost;
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