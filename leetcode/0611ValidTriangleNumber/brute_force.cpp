#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
bool validTriangle(int a,int b,int c){
    if((a+b)<=c)
        return false;
    if((a+c)<=b)
        return false;
    if((b+c)<=a)
        return false;
    return true;
}
int solve(vector<int>& nums){
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n;i++){
        for (int j = i + 1; j < n;j++){
            for (int k = j+1; k < n;k++){
                if(validTriangle(nums[i],nums[j],nums[k]))
                    ans++;
            }
        }
    }
    return ans;
}
signed main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++)
        cin >> nums[i];
    int answer = solve(nums);
    cout << "Answer : " << answer << endl;
    return 0;
}