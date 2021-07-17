#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int
int solve(vector<int>& nums){
    int n = nums.size();
    int inf = 1000 * 1000;
    vector<int> temp;
    for (int i = 0; i < n;i++){
        if(nums[i]!=0)
            temp.push_back(nums[i]);
    }
    nums.clear();
    nums = temp;
    sort(nums.begin(), nums.end());
    n = nums.size();
    int ans = (n*(n-1)*(n-2))/6;
    if(ans<=0)
        return 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {   
            int max_valid_ans = nums[i] + nums[j];
            ans -= (nums.end() - lower_bound(nums.begin(), nums.end(), max_valid_ans));
        }
    }
    return ans;
}
signed main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    int answer = solve(nums);
    cout << "Answer : " << answer << endl;
    return 0;
}