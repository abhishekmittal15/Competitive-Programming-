#include<iostream>
#include<map>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin>>n;
    map<int,int> cnt;
    for (int i = 0;i<n;i++){
        int a;
        cin >> a;
        if(cnt[a]==1)
            cnt[a] = 2;
        else
            cnt[a] = 1;
    }
    for(auto &i: cnt){
        if(i.second==1){
            cout << i.first << endl;
            break;
        }
    }
    return 0;
}