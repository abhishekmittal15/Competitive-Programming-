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
int solve(vector<int>& nums){
    int n = nums.size();
    int sum = 0;
    int subsetsCnt = power(2, n);
    for (int i = 0; i < subsetsCnt;i++){
        int ans = 0;
        for (int j = 0; j < n;j++){
            if(i&(1<<j))
                ans = ans ^ nums[j];
        }
        sum = sum + ans;
    }
    return sum;
}
signed main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++)
        cin >> nums[i];
    int answer = solve(nums);
    cout << "Answer : "<<answer << endl;
    return 0;
}