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
        int k = 0;
        int maxBit = 32;
        bool flag = false;
        for(int i=maxBit;i>=1;i--){
            if(n<=x){
                if(n!=0)
                    k++;
            // cout << n << " " << i << endl;
                n=0;
                flag=true;
                break;
            }
            if(i%2){
                if(n&(1LL<<i)){
                    k++;
                    n-=(1<<i);
                    // cout << n << endl;
                }
            }
            else if(n&(1LL<<i)){
                k++;
                n-=(1LL<<(i-1));
                // cout << n << " " << i << endl;
                if(n<=x){
                    if(n!=0)
                        k++;
                    n=0;
                    flag=true;
                    break;
                }
                n-=(1<<(i-1));
                k++;
            }
            if (n <= x)
            {
                if (n != 0)
                    k++;
                // cout << n << " " << i << endl;
                n = 0;
                flag = true;
                break;
            }
        }
        if(flag==false && n<=x)
            n = 0, k++;
        if(n!=0)    k=-1;
        cout<<k<<endl;
    }
    return 0;
}