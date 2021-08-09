#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
#define int long long int 
#define double long double 
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int inf = 1e10;
        int mx = -inf;
        double sum = 0.0;
        for (int i = 0;i<n;i++){
            int a;
            cin >> a;
            sum += a;
            mx = max(mx, a);
        }
        sum -= mx;
        sum /= (double)(n - 1);
        sum += (double)(mx);
        cout << setprecision(20)<<sum << endl;
    }
    return 0;
}