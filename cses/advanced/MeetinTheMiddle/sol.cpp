#include<iostream>
#include<vector>
#include<algorithm>
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
int solve(vector<int>& nums,int x){
    int n = nums.size();
    vector<int> sum1, sum2;
    int half = (n-1)/ 2;
    int max_subsets = power(2, half+1);
    for (int i = 0; i <max_subsets;i++){
        int sum = 0;
        for (int j = 0; j <=half;j++){
            if(i&(1<<j))
                sum += nums[j];
        }
        sum1.push_back(sum);
    }
    int rest = n - half-1;
    max_subsets = power(2, rest);
    for (int i = 0; i < max_subsets;i++){
        int sum = 0;
        for (int j = 0; j <rest;j++){
            if(i&(1<<j)){
                sum += nums[j + half + 1];
            }
        }
        sum2.push_back(sum);
    }
    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());
    int ans = 0;
    for (int i = 0; i < sum1.size();i++){
        int desired_sum = x-sum1[i];
        int cnt = upper_bound(sum2.begin(), sum2.end(), desired_sum) - lower_bound(sum2.begin(),sum2.end(),desired_sum);
        ans += cnt;
    }
    return ans;
}
signed main(){
    int n, x;
    cin>>n>>x;
    vector<int> nums(n);
    for (int i = 0; i < n;i++)
        cin >> nums[i];
    int answer = solve(nums,x);
    cout << answer << endl;
    return 0;
}