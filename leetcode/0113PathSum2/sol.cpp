#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
void solve(TreeNode* root,int targetSum,vector<vector<int>>& list,vector<int>& temp){
    if(root==nullptr)
        return;
    temp.push_back(root->val);
    if(root->left){
        solve(root->left,targetSum-root->val,list,temp);
    }
    if(root->right){
        solve(root->right,targetSum-root->val,list,temp);
    }
    if(root->left==nullptr && root->right==nullptr){
        if(targetSum==root->val)
            list.push_back(temp);
    }
    temp.pop_back();
    return ;
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> list;
    vector<int> temp;
    solve(root,targetSum,list,temp);
    return list;
}
signed main(){
    
}