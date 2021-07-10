#include<iostream>
using namespace std;
#define int long long int
signed main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        if(n%200)
            n=n*1000+200;
        else
            n=n/200;
    }
    cout<<n<<endl;
    return 0;
}