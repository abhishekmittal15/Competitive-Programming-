#include<iostream>
using namespace std;
int main(){
    int x[]={6,5,4,3,2,1};
    int a,b,c;
    cin>>a>>b>>c;
    cout<<x[a-1]+x[b-1]+x[c-1]<<endl;
    return 0;
}