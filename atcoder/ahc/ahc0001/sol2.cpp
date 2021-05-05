#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<int> a,vector<int> b){
    return a[2]<b[2];
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> ans(n);
    for(int i=0;i<n;i++){
        for(int j=0,x;j<3;j++)
            cin >> x, ans[i].push_back(x);
    }
    sort(ans.begin(),ans.end(), cmp);
    
    return 0;
}