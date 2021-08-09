#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin >> n;
    int ans = 1;
    if(n>1)
    for (int i = 2;;i++){
        int num = i;
        while (num % 2==0)
            num /= 2;
        while(num%3==0)
            num /= 3;
        while(num%5==0)
            num /= 5;
        if(num==1)
            n--;
        if(n==1){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}