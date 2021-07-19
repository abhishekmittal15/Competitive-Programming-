#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
vector<int> solve(vector<int>& nums){
    int n = nums.size();
    vector<int> cnt(n);
    for (int i = 0; i < n;i++){
        cnt[i] = 0;
        for (int j = i + 1; j < n;j++){
            if(nums[j]<nums[i])
                cnt[i]++;
        }
    }
    return cnt;
}
signed main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    vector<int> ans = solve(nums);
    for (int i = 0; i < n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}