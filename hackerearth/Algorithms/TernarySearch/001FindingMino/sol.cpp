#include<iostream>
using namespace std;
#define int long long int
int f(int x){
    return 2 * x * x + -12 * x + 7;
}
signed main(){
    int n;
    cin>>n;
    while(n--){
        int l,r;
        cin>>l>>r;
        int cur_ans = -20;
        while(l<=r){
            int mid1 = (l + (r - l) / 3);
            int mid2 = (r - (r - l) / 3);
            if(f(mid1)<f(mid2)){
                r = mid2 - 1;
                cur_ans = f(mid1);
            }
            else{
                l = mid1 + 1;
                cur_ans = f(mid2);
            }
        }
        cout << cur_ans << endl;
    }
    return 0;
}