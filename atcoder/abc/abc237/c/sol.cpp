#include<iostream>

using namespace std;

#define int long long int 
signed main(){

    string s;
    cin>>s;
    int n=s.length();
    int cnt_end=0,cnt_start=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='a')
            cnt_end++;
        else
            break;
    }
    for(int i=0;i<n;i++){
        if(s[i]=='a')
            cnt_start++;
        else
            break;
    }
    int diff=cnt_end-cnt_start;
    if(diff<0){
        cout<<"No"<<endl;
    }   
    else{
        bool flag=true;
        for(int i=cnt_start,j=n-cnt_end-1;i<n-cnt_end && j>=0;i++,j--){
            // cout<<i<<" "<<s[i]<<j<<" "<<s[j]<<endl;
            if(s[i]!=s[j]){
                flag=false;
                break;
            }
        }
        if(flag)
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }
    return 0;
}