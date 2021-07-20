#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int X, Y, s, T,cnt=0;
    cin >> X >> Y >> s >> T;
    for (int i = X; i <= X + s;i++){
        for (int j = Y; j <= Y + s;j++){
            if((i+j)<=T)
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}