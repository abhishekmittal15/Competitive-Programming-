#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& rungs,int dist){
    int prev = 0,ans=0;
    int n = rungs.size();
    for (int i = 0; i < n;i++){
        int cur = rungs[i] - prev;
        ans += (cur - 1) / dist;
        prev = rungs[i];
    }
    return ans;
}
signed main(){
    int n,dist;
    cin>>n>>dist;
    vector<int> rungs(n);
    for (int i = 0; i < n;i++){
        cin >> rungs[i];
    }
    int ans = solve(rungs,dist);
    cout << "Answer : " << ans << endl;
    return 0;
}