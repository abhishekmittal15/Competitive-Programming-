#include<iostream>
#include<vector>
#include<functional>
using namespace std;
#define int long long int 
class PrefixArray{
    private:
        vector<int> input;
        vector<int> p;
        int sz = 0;
    public:
        PrefixArray(vector<int>& a){
            sz = a.size();
            for (int i = 0; i < sz;i++){
                input.push_back(a[i]);
            }
        }
        void construct(int base,function<int(int, int)> f)
        {
            p.push_back(base);
            for (int i = 0; i < sz;i++){
                p[i + 1] = f(p[i], input[i]);
            }
        }
        int query(function<int(int,int)> g,int a,int b,int index=1){
            if(index==0)
                a++, b++;
            return g(p[b],p[a-1]);
        }
};

int f(int a, int b)
{
    return a + b;
}
int g(int a, int b)
{
    return a - b;
}

signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];
    PrefixArray pref(a);
    pref.construct(0,&f);
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << pref.query(&g,a, b) << endl;
    }
    return 0;
}