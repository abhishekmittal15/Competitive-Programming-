#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
int solve(vector<int>& nums){
    int n = nums.size();
    if(n<=3)
        return 0;
    sort(nums.begin(), nums.end());
    int ans = nums[n - 1] - nums[3];
    ans = min(ans, nums[n - 4] - nums[0]);
    ans = min(ans, nums[n - 3] - nums[1]);
    ans = min(ans, nums[n - 2] - nums[2]);
    return ans;
}
signed main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++)
        cin >> nums[i];
    int answer = solve(nums);
    cout << "Answer : " << answer << endl;
    return 0;
}