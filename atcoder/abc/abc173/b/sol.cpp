#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int n,ac=0,wa=0,tle=0,re=0;
    cin>>n;
    for (int i = 0; i < n;i++){
        string s;
        cin>>s;
        if(s=="AC")
            ac++;
        if(s=="WA")
            wa++;
        if(s=="TLE")
            tle++;
        if(s=="RE")
            re++;
    }
    cout << "AC x " << ac << endl;
    cout << "WA x " << wa << endl;
    cout << "TLE x " << tle << endl;
    cout << "RE x " << re << endl;
    return 0;
}