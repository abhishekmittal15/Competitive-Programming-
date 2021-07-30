#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
struct Trie{
    Trie *child[2] = {nullptr, nullptr};
};
int query(Trie* root,int n){
    int maxBit = 30;
    int ans = 0;
    while(maxBit--){
        int bit = (n & (1 << maxBit)) ? 1 : 0;
        int desired = 1 - bit;
        if(!root->child[desired])
            desired = bit;
        root = root->child[desired];
        ans += (desired) << maxBit;
    }
    return ans;
}
void add(Trie* root,int n){
    int maxBit = 30;
    while(maxBit--){
        int bit = (n & (1 << maxBit)) ? 1 : 0;
        if(!root->child[bit])
            root->child[bit] = new Trie();
        root = root->child[bit];
    }
}
int solve(vector<int>& nums){
    int n = nums.size();
    int ans = 0;
    Trie *root = new Trie();
    for (int i = 0;i<n;i++){
        add(root, nums[i]);
        ans = max(ans,nums[i]^ query(root, nums[i]));
    }
    return ans;
}
signed main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++)
        cin >> nums[i];
    int answer = solve(nums);
    cout << "Answer : " << answer << endl;
    return 0;
}