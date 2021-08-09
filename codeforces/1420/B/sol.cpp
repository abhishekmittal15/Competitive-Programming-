#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
struct Tree{
    Tree *child[2] = {nullptr, nullptr};
    int cnt = 0;
    void add(int a);
    int query(int a);
};
void Tree::add(int a){
    int maxBit = 32;
    Tree *ptr = this;
    for (int i = maxBit; i >= 0;i--){
        bool bit = a & (1LL << i);
        if(ptr->child[bit]==nullptr)
            ptr->child[bit] = new Tree();
        ptr = ptr->child[bit];
        ptr->cnt = ptr->cnt + 1;
    }
}
int Tree::query(int a){
    int maxBit = 32;
    Tree *ptr = this;
    for (int i = maxBit;i >= 0; i--)
    {
        bool bit = a & (1LL << i);
        ptr = ptr->child[bit];
        if(bit){
            return ptr->cnt-1;
        }
    }
    return 0;
}
signed main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        Tree *root=new Tree();
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            root->add(a[i]);
        }
        int ans = 0;
        for (int i = 0; i < n;i++){
            ans += root->query(a[i]);
        }
        cout << (ans / 2) << endl;
        delete root;
    }
    return 0;
}