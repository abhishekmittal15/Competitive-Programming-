// n=a1+a2+..+ak

// a1 can be anything between 0 and x or 
// all a1 to ak are odd powers of 2 

//    3210 
// 1000101

// k=3 (1,3,5)

#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int k_req = 0;
        int maxBit = 32;
        bool flag = false;
        for (int i = maxBit-1; i>=0;i-=2){
            if(n<=x){
                if(n!=0)
                    k_req++;
                flag = true;
                break;
            }
            if(n&(1<<i)){
                k_req++;
                n -= (1 << i);
            }
        }
        // cout << n << endl;
        if(flag){
            cout << k_req  << endl;
            continue;
        }
        // cout << "Hye" << endl;
        for (int i = maxBit; i >=2;i-=2){
            if(n<=x){
                flag = true;
                break;
            }
            if(n&(1<<i)){
                if(n>x){
                    // cout << k_req << endl;
                    k_req ++;
                    n -= (1 << (i - 1));
                    if(n<=x){
                        flag = true;
                        break;
                    }
                    k_req++;
                    n -= (1 << (i-1));
                }
            }
        }
        // cout << n << endl;
        if (flag)
        {
            if(n!=0)
                k_req++;
            cout << k_req << endl;
            continue;
        }
        else{
            // if(n==1)
            //     cout << k_req + 1 << endl;
            // else
                cout << -1 << endl;
        }
    }
    return 0;
}