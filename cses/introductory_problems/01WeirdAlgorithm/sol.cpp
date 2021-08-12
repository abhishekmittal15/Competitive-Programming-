#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin>>n;
    cout << n << " ";
    while(n!=1){
        if(n%2){
            n=n*3+1;
        }
        else 
            n/=2;
        cout << n << " ";
    }
    return 0;
}