#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
struct Trie{
    Trie *child[2] = {nullptr, nullptr};
};
void add(Trie* root, int n){
    int maxBit = 30;
    while(maxBit--){
        int bit = (n & (1 << maxBit)) ? 1 : 0;
        if(root->child[bit]==nullptr)
            root->child[bit] = new Trie();
        root = root->child[bit];
    }
}
int answer(Trie* root,int n){
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
int solve(vector<int>& nums){
    int n = nums.size();
    Trie *root=new Trie();
    int ans = 0;
    for (int i = 0; i < n;i++){
        add(root, nums[i]);
        ans = max(ans,nums[i]^answer(root, nums[i]));
    }
    return ans;
}
signed main(){
    int n;
    cin >>n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++)
        cin >> nums[i];
    int ans = solve(nums);
    cout << "Answer : " << ans << endl;
    return 0;
}


            