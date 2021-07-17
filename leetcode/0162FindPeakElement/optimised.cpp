#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solver(vector<int>& nums,int start,int end){
    if(start==end)
        return start;
    int mid = (start + end) / 2;
    if(nums[mid]<nums[mid+1])
        return solver(nums, mid + 1, end);
    return solver(nums, start,mid);
}
int solve(vector<int>& nums){
    int n = nums.size();
    return solver(nums, 0, n - 1);
}
signed main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    cout << "Answer : " << solve(nums) << endl;
    return 0;
}