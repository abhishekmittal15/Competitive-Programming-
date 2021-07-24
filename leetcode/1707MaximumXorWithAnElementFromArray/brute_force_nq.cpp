#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
vector<int> solve(vector<int>& nums,vector<vector<int>>& queries){
    int n = nums.size();
    int q = queries.size();
    vector<int> ans;
    for (int i = 0; i < q;i++){
        int x = queries[i][0];
        int m = queries[i][1];
        int val = -1;
        for (int j = 0; j < n;j++){
            if(nums[j]>m)
                continue;
            val = max(val, nums[j] ^ x);
        }
        ans.push_back(val);
    }
    return ans;
}
signed main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++)
        cin >> nums[i];
    int q;
    cin >> q;
    vector<vector<int>> queries(q);
    for (int i = 0; i < q;i++){
        int x,m;
        cin >> x >> m;
        queries[i].push_back(x);
        queries[i].push_back(m);
    }
    vector<int> answer = solve(nums, queries);
    for (int i = 0; i < answer.size();i++)
        cout << answer[i] << " ";
    cout << endl;
    return 0;
}