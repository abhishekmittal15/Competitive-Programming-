#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin>>n;
    int s = (n * (n + 1)) / 2;
    if(s%2){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int sz1 = n/2;
    int sz2 = n - sz1;
    cout << sz1 << endl;
    bool first = true;
    for (int i = n; i >=1;i-=2){
        if(first){
            cout << i << " ";
            first = false;
        }
        else{
            if(i>1)
                cout << i - 1 << " ";
            first = true;
        }
    }
    cout << endl;
    cout << sz2 << endl;
    first = true;
    for (int i = n; i >= 1; i -= 2)
    {
        if (first)
        {
            cout << i-1 << " ";
            first = false;
        }
        else
        {
            cout << i << " ";
            first = true;
        }
    }
    return 0;
}