#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin>>n;
    int q;
    cin >> q;
    vector<int> a(n);
    int cnt1 = 0;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        cnt1 += a[i];
    }
    while(q--){
        int op,val;
        cin >> op >> val;
        if(op==1){
            val--;
            if(a[val])
                cnt1--;
            else
                cnt1++;
            a[val] = 1 - a[val];
        }
        else{
            if(val>cnt1)
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
    }
    return 0;
}