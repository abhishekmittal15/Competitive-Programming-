#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& nums,int k){
    int n = nums.size();
    int cnt = 0;
    vector<int> prefix_sum(n + 1);
    prefix_sum[0] = 0;
    for (int i = 1; i <= n;i++){
        prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
    }
    for (int i = 0; i <= n;i++){
        cout << i << " " << prefix_sum[i] << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        int current_sum = prefix_sum[i];
        int desired_sum = prefix_sum[i] - k;
        int pos = lower_bound(prefix_sum.begin(), prefix_sum.end(), desired_sum) - prefix_sum.begin();
        for (int j = pos; prefix_sum[j] == desired_sum; j++){
            cnt++;
        }
    }
    return cnt;
}
signed main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    int ans = solve(nums, k);
    cout << "Answer : " << ans << endl;
    return 0;
}