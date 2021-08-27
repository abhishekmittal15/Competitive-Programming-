#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%2==1 or n==2){
            cout<<"Bob"<<endl;
            continue;
        }
        int powers = 0;
        while(n%2==0){
            powers++;
            n /= 2;
        }
        if(n>1 or powers%2==0)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    return 0;
}