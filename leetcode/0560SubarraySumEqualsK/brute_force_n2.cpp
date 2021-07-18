#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& nums,int k){
    int n = nums.size();
    int cnt = 0;
    vector<int> prefix_sum(n+1);
    prefix_sum[0] = 0;
    for (int i = 1; i <=n;i++)
        prefix_sum[i] = prefix_sum[i - 1] + nums[i-1];
    for (int i = 1; i <=n; i++)
    {
        for (int j = i; j <=n; j++)
        {
            if((prefix_sum[j]-prefix_sum[i-1])==k)
                cnt++;
        }
    }
    return cnt;
}
signed main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    int answer = solve(nums,k);
    cout << "Answer : " << answer << endl;
    return 0;
}