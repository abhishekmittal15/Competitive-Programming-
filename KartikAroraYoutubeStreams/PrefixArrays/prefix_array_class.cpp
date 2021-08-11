#include<iostream>
#include<vector>
#include<functional>
using namespace std;
#define int long long int

template<class T> 
class PrefixArray{
    private:
        vector<T> input;
        vector<T> p;
        int sz = 0;
    public:
        PrefixArray(vector<T>& a){
            sz = a.size();
            for (int i = 0; i < sz;i++){
                input.push_back(a[i]);
            }
            for (int i = 0; i < sz;i++)
                cout << input[i] << " ";
            cout << endl;
        }
        void construct(T base,function<T(T, T)> f)
        {
            p.push_back(base);
            for (int i = 0; i < sz;i++){
                p[i + 1] = f(p[i], input[i]);
            }
        }
        T query(function<T(T,T)> g,int a,int b,int index=1){
            if(index==0)
                a++, b++;
            return g(p[b],p[a-1]);
        }
};

double f(double a, double b)
{
    return a + b;
}
double g(double a, double b)
{
    return a - b;
}

signed main(){
    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];
    PrefixArray<double> pref(a);
    pref.construct(0.0,&f);
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << pref.query(&g,a, b) << endl;
    }
    return 0;
}