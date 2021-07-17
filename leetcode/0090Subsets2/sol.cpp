#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
int power(int a,int b){
    int ans = 1;
    for (int i = 0;i<b;i++)
        ans = ans * a;
    return ans;
}
vector<vector<int>> solve(vector<int>& nums){
    map<vector<int>, bool> exists;
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int subsets_cnt = power(2, n);
    for (int i = 0; i < subsets_cnt;i++){
        vector<int> temp;
        for (int j = 0; j < n;j++){
            if(i&(1<<j))
                temp.push_back(nums[j]);
        }
        if(exists[temp]==false){
            result.push_back(temp);
            exists[temp] = true;
        }
    }
    return result;
}
signed main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    vector<vector<int>> answer = solve(nums);
    for (int i = 0; i < answer.size();i++){
        for (int j = 0; j < answer[i].size();j++){
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}