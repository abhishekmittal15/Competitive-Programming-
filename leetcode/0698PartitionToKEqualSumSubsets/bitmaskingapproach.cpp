#include <iostream>
#include <vector>
using namespace std;
#define int long long int
int power(int a,int b){
    int ans = 1;
    while(b>0){
        if(b&1)
            ans = ans * a;
        a = a * a;
        b /= 2;
    }
    return ans;
}
bool func(vector<int>& nums,int req){
    int n = nums.size();
    vector<int> temp;
    int max_subsets = power(2, n);
    for (int mask = 0; mask < max_subsets;mask++){
        int sum = 0;
        for (int j = 0; j < n;j++)
            if(mask&(1<<j))
                sum += nums[j];
        if(sum==req){
            for (int j = 0; j < n;j++)
                if((mask&(1<<j))==0)
                    temp.push_back(nums[j]);
            nums.clear();
            nums.resize(temp.size());
            for (int i = 0; i < temp.size(); i++)
                nums[i] = temp[i];
            return true;
        }
    }
    return false;
}
bool solve(vector<int>& nums,int k){
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n;i++)
        sum += nums[i];
    if(sum%k)
        return false;
    int req = sum / k;
    bool ans = true;
    for (int i = 1; i <=k;i++){
        ans = ans & func(nums,req);
        for(auto i:nums)
            cout << i << " ";
        cout << endl;
    }
    return ans;
}
signed main()
{
    int n,k;
    cin >> n>>k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    bool ans = solve(nums,k);
    cout << "Answer : "<<ans << endl;
    return 0;
}