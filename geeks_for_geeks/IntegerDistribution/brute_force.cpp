#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
vector<int> solve(vector<int>& nums){
    int n = nums.size();
    vector<int> result;
    int mx = 0, mn = 1e9 + 7;
    sort(nums.begin(), nums.end());
    do{
        int ans = 0;
        for (int i = 0; i < n;i+=2){
            ans += (nums[i] ^ nums[i + 1]);
        }
        mx = max(mx, ans);
        mn = min(mn, ans);
    } while (next_permutation(nums.begin(), nums.end()));
    result.push_back(mx);
    result.push_back(mn);
    return result;
}
signed main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++)
        cin >> nums[i];
    vector<int> ans = solve(nums);
    cout << "Largest : " << ans[0] << endl;
    cout << "Smallest : " << ans[1] << endl;
    return 0;
}