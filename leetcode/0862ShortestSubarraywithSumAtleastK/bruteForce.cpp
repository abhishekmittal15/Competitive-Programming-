#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& nums,int k){
    int n = nums.size();
    int ans = n + 10;
    vector<int> prefix_sum(n+1);
    prefix_sum[0] = 0;
    for (int i = 1; i <= n;i++)
        prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
    for (int left = 1; left <=n; left++){
        for (int right = left; right <=n;right++){
            int sum = prefix_sum[right] - prefix_sum[left - 1];
            if(sum>=k)
                ans = min(ans, right - left + 1);
        }
    }
    if(ans==(n+10))
        ans = -1;
    return ans;
}
signed main(){
    int n,k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n;i++)
        cin >> nums[i];
    int answer = solve(nums, k);
    cout << "Answer : " << answer << endl;
    return 0;
}