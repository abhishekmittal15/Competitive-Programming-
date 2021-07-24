#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& nums){
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n;i++)
        sum += nums[i];
    int half_sum = (sum+1) / 2;
    // if you do half_sum=sum/2+1, then it fails on 8 5 6 6 5 11 5 8, basically on testcases where sum is exactly divisible by 2 
    vector<vector<bool>> dp(n + 1, vector<bool>(half_sum+1, false));
    for (int i = 0; i <= n;i++)
        dp[i][0] = true;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= half_sum;j++){
            dp[i][j] = dp[i - 1][j];
            if(j>=nums[i-1])
                dp[i][j]=dp[i][j] | dp[i - 1][j - nums[i - 1]];
        }
    int ans = -1;
    for (int i = half_sum; i >=0;i--){
        for (int j = 1; j <= n;j++)
            if(dp[j][i]==true){
                ans = i;
                break;
            }
        if(ans!=-1)
            break;
    }
    return abs(sum - 2 * ans);
    return false;
}
signed main(){
    int n;
    cin >>n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin>>nums[i];
    }
    int answer = solve(nums);
    cout << "Answer : " << answer << endl;
    return 0;
}