#include<iostream>
#include<iomanip>
using namespace std;
#define int long long int 
#define double long double
double power(double a,int b){
    double res = 1;
    while(b>0){
        if(b&1)
            res = res * a;
        b /= 2;
        a = a * a;
    }
    return res;
}
signed main(){
    int m,n;
    cin >> m >> n;
    double ans = m;
    for (int i = 1; i < m;i++){
        double val = power((double)((double)(i) /(double)(m)), n);
        ans -= val;
    }
    cout << setprecision(10) << ans << endl;
    return 0;
}