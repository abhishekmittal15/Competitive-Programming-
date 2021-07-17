#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& nums){
    int n = nums.size();
    for (int i = 0; i < n;i++){
        if(i==0 && nums[i]>nums[i+1])
            return i;
        if(i==n-1 && nums[i]>nums[i-1])
            return i;
        if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
            return i;
    }
}
signed main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    cout << "Answer : " << solve(nums) << endl;
    return 0;
}