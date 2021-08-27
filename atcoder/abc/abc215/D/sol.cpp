#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
#define int long long int
int maxn = 1e5+5;
vector<bool> sieve(maxn,true);
vector<int> spf(maxn);
void s(){
    for (int i = 2; i < maxn;i++)
        spf[i] = i;
    for (int i = 2; i * i <= maxn; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j < maxn; j += i)
                sieve[j] = false, spf[j] = min(i,spf[j]);
        }
    }
} 
vector<int> f(int n){
    vector<int> factors;
    while(n>1){
        factors.push_back(spf[n]);
        n /= spf[n];
    }
    return factors;
}
signed main(){
    s();
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<bool> valid = sieve;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        vector<int> result = f(a[i]);
        for (int j = 0; j < result.size();j++){
            valid[result[j]] = false;
        }
    }
    vector<int> res;
    for (int i = 1; i <= m;i++){
        vector<int> result = f(i);
        bool flag = true;
        for (int j = 0; j < result.size();j++){
            if(valid[result[j]]==false)
                flag = false;
        }
        if(flag)
            res.push_back(i);
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size();i++)
        cout << res[i] << endl;
    return 0;
}