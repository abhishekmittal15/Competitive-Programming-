#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
bool rec(vector<int>&nums,vector<int>& subsets,int req,int idx=0){
    int n = nums.size();
    if(idx==n){
        for (int i = 0; i < subsets.size();i++){
            if(subsets[i]!=req)
                return false;
        }
        return true;
    }
    bool ans = false;
    for (int i = 0; i < subsets.size();i++){
        subsets[i] += nums[idx];
        ans = ans | rec(nums, subsets, req, idx + 1);
        subsets[i] -= nums[idx];
    }
    return ans;
}
bool solve(vector<int>& nums){
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n;i++)
        sum += nums[i];
    sort(nums.begin(), nums.end());
    int k = 4;
    if(sum%k)
        return false;
    vector<int> subsets(k);
    return rec(nums, subsets,sum/k);
}
signed main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++)
        cin >> nums[i];
    bool answer = solve(nums);
    cout << "Answer : " << answer << endl;
    return 0;
}