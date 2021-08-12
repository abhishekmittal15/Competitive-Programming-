// #include<iostream>
// using namespace std;
// #define int long long int 
// signed main(){
//     int n;
//     cin>>n;
//     int ans = 0;
//     int divisibleby2 = n / 2;
//     int divisibleby5 = n / 5;
//     int divisibleby10 = n / 10;
//     divisibleby2 -= divisibleby10;
//     divisibleby5 -= divisibleby10;
//     ans = (min(divisibleby2, divisibleby5) + divisibleby10);
//     cout << ans << endl;
//     return 0;
// }

#include<iostream>
using namespace std;
#define int long long int
signed main(){
    int n;
    cin>>n;
    int ans = 0;
    for (int i = 5;i<=n;i=i*5){
        ans += (n / i);
    }
    cout << ans << endl;
    return 0;
}

// https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/