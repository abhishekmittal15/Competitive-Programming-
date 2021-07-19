#include<iostream>
#include<vector>
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
bool solve(vector<int>& nums){
    int n = nums.size();
    int max_subsets = power(2, n);
    for (int i = 1; i < max_subsets-1;i++){
        int sum1 = 0, sum2 = 0, cnt1 = 0, cnt2 = 0;
        for (int j = 0; j < n;j++){
            if(i&(1<<j)){
                sum1 += nums[j];
                cnt1++;
            }
            else{
                sum2 += nums[j];
                cnt2++;
            }
        }
        if((sum2*cnt1)==(sum1*cnt2))
            return true;
    }
    return false;
}
signed main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    bool ans = solve(nums);
    cout << "Answer : " << ans << endl;
    return 0;
}