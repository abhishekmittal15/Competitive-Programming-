#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& nums){
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];
    int half_sum = (sum + 1) / 2;
    vector<bool> dp(half_sum + 1, false),dd(half_sum+1,false);
    dp[0] = true;
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= half_sum; j++)
            if (j >= nums[i])
                dd[j] = dp[j] | dp[j - nums[i]]; // here dd[j] is required, because lets say dp[11] is made true in this loop because nums[i]=11, then as j increases to 22, again dp[i] becomes true because dp[11] is true, but this is wrong as 11 is counted twice. Hence we update dd[11] rather than dp[11], avoiding false updations to the dp array.
        for (int j = 1; j <= half_sum;j++){
            if(dd[j])
                dp[j] = true;
            dd[j] = false;
        }
    }
    int ans = -1;
    for (int i = half_sum; i >= 0; i--)
        if (dp[i] == true)
        {
            ans = i;
            break;
        }
    cout << ans << endl;
    return abs(sum - 2 * ans);
    // It was initially failing at testcase 5 11 18 24 18 18
}
signed main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++)
        cin >> nums[i];
    int ans = solve(nums);
    cout << "Answer : " << ans << endl;
    return 0;
}