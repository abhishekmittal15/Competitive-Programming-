#include<iostream>
using namespace std;
#define int long long int 
double solve(int n){
    if(n==1)
        return 1.000000;
    return 0.500000;
}
signed main(){
    int n;
    cin>>n;
    double ans=solve(n);
    cout<<"Answer : "<<ans<<endl;
    return 0;
}