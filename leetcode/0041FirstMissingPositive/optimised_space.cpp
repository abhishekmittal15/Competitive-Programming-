#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& nums){
    int n=nums.size();
    
    // Set up the vector by changing the negative and 0 elements
    for (int i = 0; i < n;i++)
        if(nums[i]<=0)
            nums[i] = n + 1;
    
    // Iterate over the vector and mark the presence of the element by marking the value at that index as negative
    for (int i = 0; i < n;i++){
        int index = abs(nums[i]) - 1;
        nums[index] *= (-1);
    }

    // Iterate over the vector and find the 1st positive element
    for (int i = 0; i < n;i++){
        if(nums[i]>0)
            return i + 1;
    }
    return n + 1;
}
signed main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++)
        cin >> nums[i];
    cout << "Answer : " << solve(nums) << endl;
    return 0;
}