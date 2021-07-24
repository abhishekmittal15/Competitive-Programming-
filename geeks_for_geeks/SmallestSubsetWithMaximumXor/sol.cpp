#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int inf=1000*1000*1000+7;
int solve(int i,int current_or,vector<int>& nums,vector<vector<int>>& dp,int maxOr){
    int n = nums.size();
    if(i==n){
        if(current_or==maxOr)
            return 0;
        return inf;
    }
    if(dp[i][current_or]!=-1)
        return dp[i][current_or];
    dp[i][current_or] = min(solve(i + 1, current_or, nums, dp, maxOr), 1 + solve(i + 1, current_or | nums[i], nums, dp, maxOr));
    return dp[i][current_or];
}
signed main(){
    int n,maxOr=0;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i],maxOr|=nums[i];
    vector<vector<int>> dp(n, vector<int>(maxOr + 1, -1));
    int answer=solve(0,0,nums,dp,maxOr);
    cout << "Answer : " << answer << endl;
    return 0;
}