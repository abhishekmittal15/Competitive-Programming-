#include<iostream>
#include<vector>

using namespace std;

#define int long long int 

bool is_prime(int a){
    
    int cnt=0;
    for(int i=2;i<a;i++){
        if(a%i==0)
            cnt++;
    }
    return !(cnt>0);
}

signed main(){

    int a,b,c,d;
    cin>>a>>b>>c>>d;
    bool flag=false;
    for(int i=a;i<=b;i++){
        int cnt=0;
        for(int j=c;j<=d;j++){
            if(is_prime(i+j)==false)
                cnt++;
        }
        if(cnt==d-c+1){
            flag=true;
            break;
        }
    }
    if(flag)
        cout<<"Takahashi"<<endl;
    else    
        cout<<"Aoki"<<endl;
    return 0;
}