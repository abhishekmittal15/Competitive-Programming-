#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& nums){
    int ans = 0;
    int mod = 1000 * 1000 * 1000 + 7;
    int n = nums.size();
    for (int num = 0; num < n;num++){
        for (int den = 0; den < n;den++){
            ans += (nums[num] / nums[den]);
            ans = (ans >= mod) ? ans - mod : ans;
        }
    }
    return ans;
}
signed main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++)
        cin >> nums[i];
    int answer = solve(nums);
    cout << "Answer : " << answer << endl;
    return 0;
}