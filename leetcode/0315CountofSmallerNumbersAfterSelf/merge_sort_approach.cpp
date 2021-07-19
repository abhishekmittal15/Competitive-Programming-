#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
void merge(vector<vector<int>>& nums,int start1,int end1,int start2,int end2,vector<int>& cnt){
    vector<int> left,left_ind,right_ind, right;
    for (int i = start1;i<=end1;i++){
        left.push_back(nums[i][0]);
        left_ind.push_back(nums[i][1]);
        // cout << nums[i][1] << " " << nums[i][0] << endl;
    }
    for (int i = start2; i <= end2; i++){
        right.push_back(nums[i][0]);
        right_ind.push_back(nums[i][1]);
        // cout << nums[i][1] << " " << nums[i][0] << endl;
    }
    for (int i = start1; i <= end1; i++)
    {
        auto it = lower_bound(right.begin(), right.end(), nums[i][0]);
        int num_elements_smaller = it - right.begin();
        cnt[nums[i][1]] += num_elements_smaller;
        // cout << start1 << " " << end1 << " " << start2 << " " << end2 << endl;
        // cout << "Current counts" << endl;
        // for (int i = 0; i < cnt.size();i++)
        //     cout << cnt[i] << " ";
        // cout << endl;
    }
    int i = 0, j = 0,k=start1;
    int limit1 = end1 - start1 ;
    int limit2 = end2 - start2 ;
    while(i<=limit1 && j<=limit2){
        nums[k].clear();
        if(left[i]<right[j]){
            nums[k].push_back(left[i]);
            nums[k].push_back(left_ind[i]);
            i++, k++;
        }
        else{
            nums[k].push_back(right[j]);
            nums[k].push_back(right_ind[j]);
            j++, k++;
        }
    }
    while(i<=limit1){
        nums[k].clear();
        nums[k].push_back(left[i]);
        nums[k].push_back(left_ind[i]);
        i++, k++;
    }
    while (j <= limit2)
    {
        nums[k].clear();
        nums[k].push_back(right[j]);
        nums[k].push_back(right_ind[j]);
        j++, k++;
    }
}
void divide(vector<vector<int>>& nums,int start,int end,vector<int>& cnt){
    if(start==end)
        return;
    int mid = (start + end) / 2;
    divide(nums, start, mid, cnt);
    divide(nums, mid + 1, end, cnt);
    merge(nums, start, mid, mid + 1, end, cnt);
}
vector<int> solve(vector<int>& nums){
    vector<vector<int>> temp;
    int n = nums.size();
    vector<int> tmp;
    for (int i = 0; i < n;i++){
        tmp.clear();
        tmp.push_back(nums[i]);
        tmp.push_back(i);
        temp.push_back(tmp);
    }
    vector<int> cnt(n,0);
    divide(temp, 0, n - 1,cnt);
    // for (int i = 0; i < n;i++){
    //     cout << temp[i][0] << " " << temp[i][1] << endl;
    // }
    return cnt;
}
signed main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    vector<int> answer = solve(nums);
    for (int i = 0; i < n;i++){
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}