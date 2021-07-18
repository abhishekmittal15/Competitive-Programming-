#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int neginf =-1* 1000 * 1000 * 1000 + 7;
int construct(vector<int>& seg,vector<int>& nums,int start,int end,int index){
    if(start==end)
        return seg[index]=nums[start];
    int mid = (start + end) / 2;
    seg[index] = max(construct(seg, nums, start, mid, index * 2 + 1), construct(seg, nums, mid + 1, end, index * 2 + 2));
    return seg[index];
}
int find(vector<int>& seg,int qs,int qe,int ss,int se,int index){
    if(qs>se || ss>qe)
        return neginf;
    if(qs<=ss && qe>=se)
        return seg[index];
    int mid = (ss + se) / 2;
    int left = find(seg, qs, qe, ss, mid, index * 2 + 1);
    int right = find(seg, qs, qe, mid+1, se, index * 2 + 2);
    return max(left, right);
}
vector<int> solve(vector<int>& nums,int k){
    int n = nums.size();
    vector<int> result;
    vector<int> seg(4 * n,0);
    construct(seg,nums, 0, n - 1,0);
    for (int i = 0; i <=n-k;i++){
        result.push_back(find(seg, i, i + k - 1, 0, n - 1, 0));
    }
    return result;
}
signed main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    vector<int> answer = solve(a,k);
    for (int i = 0; i < answer.size();i++){
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}