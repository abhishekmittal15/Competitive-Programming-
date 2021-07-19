// we want sum(A)/cnt(A)=sum(B)/cnt(B)
// So this is basically sum(A)/cnt(A)=(sum-sum(A))/(n-cnt(A))
// solving this we get sum(A)*(n-cnt(A))=(sum-sum(A))*cnt(A)
// sum(A)*n=sum*cnt(A)
// sum(A)=(sum*cnt(A))/n => this is helpful in pruning arrays which definitely dont satisfy the condition 

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
#define int long long int 
bool solve(vector<int>& nums){
    int n = nums.size();
    int totalSum = 0;
    for (int i = 0; i < n;i++){
        totalSum += nums[i];
    }
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        if ((totalSum*i)%n==0)
            flag = true;
    }
    if(flag==false)
        return false;
    
    // Pruning is done
    int m = n / 2;
    vector<unordered_set<int>> sums(m + 1);
    sums[0].insert(0);
    for (int num : nums)
    {
        for (int i = m; i >= 1; --i)
            for (const int t : sums[i - 1])
                sums[i].insert(t + num);
    }
    for (int i = 1; i <= m; ++i)
        if (totalSum * i % n == 0 && sums[i].find(totalSum * i / n) != sums[i].end())
            return true;
    return false;
}
signed main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    bool ans = solve(nums);
    cout << "Answer : " << ans << endl;
    return 0;
}