#include<iostream>
#include<vector>
using namespace std;
#define int long long int 

vector<int> solve(int n){
    vector<int> ans;
    for(int i=0;i<=n;i++){
        ans.push_back(__builtin_popcount(i));
    }
    return ans;
}

signed main(){
    int n;
    cin>>n;
    vector<int> answer=solve(n);
    for(int i=0;i<=n;i++){
        cout<<answer[i]<<endl;
    }
    return 0;
}
