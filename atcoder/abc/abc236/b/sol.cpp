#include<iostream>
using namespace std;

#define int long long int 

signed main(){

    int n;
    cin>>n;
    int sum = 0;
    for (unsigned int i = 0; i < 4 * n-1;i++){
        int a;
        cin >> a;
        sum += a;
    }
    int original_sum = 2 * (n) * (n + 1);
    cout << original_sum - sum << endl;
    return 0;
}