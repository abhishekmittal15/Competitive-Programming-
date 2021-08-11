#include<iostream>
#include<vector>
using namespace std;
#define int long long int 

int f(int a,int b){
    return a + b;
}
int g(int a,int b){
    return a - b;
}
class PrefixArray{
    private:
        vector<int> p;
        int sz = 0;
    public:
        PrefixArray(vector<int>& a){
            sz = a.size();
            p.push_back(0);
            for (int i = 0;i<sz;i++)
                p.push_back(f(p[i],a[i]));
        }
        int query(int a,int b,int index=1){
            if(index==0)
                a++, b++;
            return g(p[b],p[a-1]);
        }
};

signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];
    PrefixArray pref(a);
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << pref.query(a, b) << endl;
    }
    return 0;
}