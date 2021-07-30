#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& nums){
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n;i++)
        for (int j = 0; j < n;j++)
            ans = max(ans, nums[i] ^ nums[j]);
    return ans;
}
signed main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    int answer=solve(nums);
    cout << "Answer : " << answer << endl;
    return 0;
}