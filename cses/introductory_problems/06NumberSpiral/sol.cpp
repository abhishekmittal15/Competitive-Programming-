#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin>>n;
    while(n--){
        int x, y;
        cin >> y>>x;
        bool swapped = false;
        int temp = y;
        y = max(x, temp);
        if(y!=temp)
            swapped = true;
        x = min(temp, x);
        int ele = 0;
        if(y%2){
            ele = (y - 1) * (y - 1) + x;
        }
        else{
            ele = y * y - x + 1;
        }
        if(swapped){
            if(y%2)
                ele += (2 * (y - x));
            else
                ele -= (2 * (y - x));
        }
        cout << ele << endl;
    }
    return 0;
}