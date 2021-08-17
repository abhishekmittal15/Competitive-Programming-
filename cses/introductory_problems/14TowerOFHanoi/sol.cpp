#include<iostream>
using namespace std;
#define int long long int
void f(int n,int from,int to,int aux){
    if(n==1){
        cout << from << " " << to << endl;
        return;
    }
    f(n - 1, from, aux, to);
    cout<<from<<" "<<to<<endl;
    f(n - 1, aux, to, from);
}
signed main(){
    int n;
    cin>>n;
    cout << (1ll << n) - 1 << endl;
    f(n, 1, 3, 2);
    return 0;
}