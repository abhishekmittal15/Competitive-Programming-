#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& nums){
    int n = nums.size();
    vector<int> bits(30,0);
    for (int i = 0; i < n;i++)
        for (int j = 0; j < 30;j++)
            if(nums[i]&(1<<j))
                bits[j]++;
    int ans = 0;
    for (int i = 0; i < 30;i++)
        ans += (bits[i] * (n - bits[i]) * (1 << i));
    return ans;
}
signed main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++)
        cin >> nums[i];
    int ans = solve(nums);
    cout << "Answer : " << ans << endl;
    return 0;
}
