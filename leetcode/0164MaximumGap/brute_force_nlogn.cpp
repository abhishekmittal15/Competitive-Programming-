#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
int solve(vector<int>& nums){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 1; i < n;i++){
        ans = max(ans, nums[i] - nums[i - 1]);
    }
    return ans;
}
signed main(){
    int n;
    cin>.n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    int ans = solve(nums);
    cout << "Answer : " << ans << endl;
    return 0;
}