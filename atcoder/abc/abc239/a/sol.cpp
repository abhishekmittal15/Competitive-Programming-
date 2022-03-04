#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main(){
    double h;
    cin>>h;
    double ans=sqrt(h*((double)(12800000)+h));
    cout<<setprecision(10)<<ans<<endl;
    return 0;

}