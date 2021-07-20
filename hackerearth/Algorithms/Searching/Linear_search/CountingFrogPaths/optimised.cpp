#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int x, y, s, t,cnt=0;
    cin >> x >> y >> s >> t;
    for (int i = 0,j=t; i <= t;i++,j--){
        if(i>=x && i<=(x+s)){
            cnt += (min(max(j - y + 1, 1LL*0), s + 1));
        }
    }
    cout << cnt << endl;
    return 0;
}