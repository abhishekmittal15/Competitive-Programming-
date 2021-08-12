#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        bool flag = (((2 * b - a) % 3 == 0) && ((2 * a - b) % 3 == 0) &&(2*b>=a) && (2*a>=b));
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}