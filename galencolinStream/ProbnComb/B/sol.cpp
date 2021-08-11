// #include<iostream>
// #include<iomanip>
// using namespace std;
// #define int long long int
// #define double long double 
// #define one 1ll
// signed main(){
//     double a,b,c,d;
//     cin>>a>>b>>c>>d;
//     double p1w=a/b;
//     double p1l=1-p1w;
//     double p2w=c/d;
//     double p2l=1-p2w;
//     double ans = 0.0;
//     double precision = 1e-7;
//     double null_result = 1.0;
//     double null_match = p1l * p2l;
//     while(true){
//         double cur = null_result * p1w;
//         if(cur<precision)
//             break;
//         double cur_ans = ans + cur;
//         ans = cur_ans;
//         null_result *= null_match;
//     }
//     cout <<setprecision(10)<< ans << endl;
//     return 0;
// }

// A Simpler solution is to use Indicator variables to calculate the answer 

#include<iostream>
#include<iomanip>
using namespace std;
#define int long long int 
#define double long double 
#define one 1ll
signed main(){
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    double p1w = a / b;
    double p1l = 1-p1w;
    double p2w = c / d;
    double p2l = 1-p2w;
    double ans = (p1w) / (1 - p1l * p2l);
    cout << setprecision(10) << ans << endl;
    return 0;
}