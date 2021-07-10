#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=n/100;
    if(n%100)
        ans++;
    cout<<ans<<endl;
    return 0;
}