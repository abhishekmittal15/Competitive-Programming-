#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=1000*1000;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int intervalscnt=pow(2,n-1);
    for(int i=0;i<intervalscnt;i++){
        int xorval=0;
        int orval=a[0];
        for(int j=1;j<n;j++){
            int set=i&(1<<(j-1));
            if(set){
                xorval=xorval^orval;
                orval=0;
            }
            else{
                orval=orval|a[j];
            }
        }
        cout << xorval << endl;
        ans=min(ans,xorval);
    }
    cout << ans << endl;
    return 0;
}