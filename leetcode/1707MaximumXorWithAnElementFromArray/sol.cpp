#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
struct Trie{
    Trie *child[2] = {nullptr, nullptr};
};
void add(Trie* root,int n){
    int maxBit = 32;
    while(maxBit--){
        int bit = (n & (1 << maxBit)) ? 1 : 0;
        if(root->child[bit]==nullptr)
            root->child[bit] = new Trie();
        root = root->child[bit];
    }
}
int query(Trie* root,int val, int ub){
    int maxBit = 32;
    int ans = 0;
    bool touched = true;
    while(maxBit--){
        int val_bit = (val & (1 << maxBit))?1:0;
        int ub_bit = (ub & (1 << maxBit))?1:0;
        int desired = 1 - val_bit;
        if(root->child[desired]==nullptr)
            desired = val_bit;
        if(touched){
            if(desired>ub_bit){
                desired = ub_bit;
            }
            if(desired<ub_bit)
                touched = false;
        }
        if(root->child[desired]){
            root = root->child[desired];
            ans += (desired) << maxBit;
            // cout << maxBit<<" "<<val_bit << " " << ub_bit << " " << desired << " " << touched << " "<<ans << endl;
        }
        else
            return -1;
    }
    return ans;
}

// desired ub_bit
// 0           0  touched=true, desired=0
// 0           1  touched=false, desired=0
// 1           0  touched=true, desired=0
// 1           1  touched=true, desired=1
vector<int> solve(vector<int>& nums,vector<vector<int>>& queries){
    int n = nums.size();
    int q = queries.size();
    vector<int> result;
    Trie *root = new Trie();
    for (int i = 0; i < n;i++)
        add(root, nums[i]);
    for (int i = 0; i < q;i++){
        int val = queries[i][0];
        int ub = queries[i][1];
        result.push_back(val^query(root, val, ub));
    }
    return result;
}
signed main(){
    int n,q;
    cin >> n >> q;
    vector<int> nums(n);
    vector<vector<int>> queries(q,vector<int>(2));
    for (int i = 0; i < n;i++)
        cin>>nums[i];
    for (int i = 0; i < q;i++){
        cin >> queries[i][0] >> queries[i][1];
    }
    vector<int> ans = solve(nums, queries);
    for (int i = 0; i < q;i++){
        cout << queries[i][0] << " " << queries[i][1] << " " << ans[i] << endl;
    }
    return 0;
}