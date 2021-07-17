#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
ostream& operator<<(ostream& os,const vector<int>& a){
    for (int i = 0; i < a.size();i++){
        os << a[i] << " ";
    }
    return os;
}
vector<int> solve(vector<int>& nums,int maximumBit){
    vector<int> result;
    int n = nums.size(), ansXor = 0;
    for(int i=0;i<n;i++){
        ansXor = ansXor^nums[i];
    }
    for (int i = n - 1; i >= 0;i--){
        int ans = 0;
        for (int j = 0; j < maximumBit;j++){
            if(ansXor&(1<<j))
                continue;
            ans += (1 << j);
        }
        result.push_back(ans);
        ansXor = ansXor^nums[i];
    }
    return result;
}
signed main(){
    int n,maximumBit;
    cin >> n >> maximumBit;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    vector<int> answer = solve(nums, maximumBit);
    cout << answer << endl;
    return 0;
}