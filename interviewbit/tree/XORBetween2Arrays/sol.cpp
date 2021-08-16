#include<iostream>
#include<vector>
using namespace std;
#define int long long int
struct Node{
    Node *child[2] = {nullptr, nullptr};
};
void add(int n,Node* root){
    int maxBit = 3;
    for (int i = maxBit; i >= 0;i--){
        bool bit = n & (1 << i);
        if(root->child[bit]==nullptr)
            root->child[bit] = new Node;
        root = root->child[bit];
    }
}
int query(int n,Node* root){
    int maxBit = 3;
    int ans = 0;
    for (int i = maxBit; i >= 0;i--){
        bool bit = n & (1 << i);
        bool desired = 1 - bit;
        if(root->child[desired]==nullptr){
            desired = bit;
        }
        ans += (desired << i);
        root = root->child[desired];
    }
    return ans;
}
int solve(vector<int>&a,vector<int>&b){
    Node *root = new Node;
    int n1=a.size();
    int n2 = b.size();
    for (int i = 0; i < n1;i++){
        add(a[i], root);
    }
    int ans = -1;
    for (int i = 0; i < n2;i++){
        ans = max(ans, b[i]^query(b[i], root));
    }
    return ans;
}   
signed main(){
    int n1,n2;
    cin >> n1 >> n2;
    vector<int> a(n1), b(n2);
    for (int i = 0; i < n1;i++)
        cin >> a[i];
    for (int i = 0; i < n2; i++)
        cin >> b[i];
    int ans = solve(a,b);
    cout << "Answer : " << ans << endl;
    return 0;
}