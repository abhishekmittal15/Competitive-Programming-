#include<iostream>
#include<math.h>
using namespace std;
#define int long long int 
int solve(int n){
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int k=sqrt(i*i+j*j);
            if(k<=n)
                if((i*i+j*j)==k*k)
                    ans++;
        }   
    }
    return ans;
}
signed main(){
    int n;
    cin>>n;
    int ans=solve(n);
    cout<<"Answer : "<<ans<<endl;
    return 0;
}