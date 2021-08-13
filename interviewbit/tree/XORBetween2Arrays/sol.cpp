#include<iostream>
#include<vector>
using namespace std;
// #define int long long int
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
        // cout << bit << " " << desired << endl;
        cout << ans << endl;
        if(root->child[desired])
            ans += (desired << i);
        else if(root->child[bit])
            ans += (bit << i);
    }
    return ans;
}
int solve(int *a,int n1,int *b,int n2){
    Node *root = new Node;
    cout << "Entered" << endl;
    for (int i = 0; i < n1;i++){
        add(a[i], root);
        cout << "Added " << a[i] << endl;
    }
    int ans = -1;
    for (int i = 0; i < n2;i++){
        ans = max(ans, query(b[i], root));
        cout << "Queried " << b[i] << endl;
    }
    return ans;
}   
signed main(){
    int n1,n2;
    cin >> n1 >> n2;
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1;i++)
        cin >> a[i];
    for (int i = 0; i < n2; i++)
        cin >> b[i];
    int ans = solve(a, n1, b, n2);
    cout << "Answer : " << ans << endl;
    return 0;
}