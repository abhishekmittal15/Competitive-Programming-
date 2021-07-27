#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
vector<int> solve(vector<int>& parents,vector<vector<int>>& queries){
    vector<int> result;
    int q = queries.size();
    for (int i = 0; i < q;i++){
        int node = queries[i][0];
        int val = queries[i][1];
        int ans = 0;
        while(node!=-1){
            ans = max(ans, val ^ node);
            node = parents[node];
        }
        result.push_back(ans);
    }
    return result;
}
signed main(){
    int n,q;
    cin>>n>>q;
    vector<int> parents(n);
    for (int i = 0; i < n;i++)
        cin >> parents[i];
    vector<vector<int>> queries(q,vector<int>(2));
    for (int i = 0; i < q;i++){
        cin >> queries[i][0] >> queries[i][1];
    }
    vector<int> ans = solve(parents, queries);
    for (int i = 0; i < q;i++){
        cout << ans[i] << endl;
    }
    return 0;
}