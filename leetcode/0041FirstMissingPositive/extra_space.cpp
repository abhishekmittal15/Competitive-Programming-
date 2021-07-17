#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& nums){
    int n = 5 * 1000 * 100 + 5;
    vector<int> present(n, -1);
    int sz = nums.size();
    for (int i = 0; i < sz; i++)
    {
        if (nums[i] > 0 && nums[i] < n)
            present[nums[i]] = 1;
    }
    int ans = -1;
    for (int i = 1; i < n; i++)
    {
        if (present[i] == -1)
        {
            ans = i;
            break;
        }
    }
    return ans;
}
signed main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Answer : "<<solve(nums)<<endl;
    return 0;
}