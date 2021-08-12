#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin>>n;
    int sum = 0;
    for (int i = 0; i < (n-1);i++){
        int a;
        cin>>a;
        sum += a;
    }
    cout << (n * (n + 1) / 2) - sum << endl;
}