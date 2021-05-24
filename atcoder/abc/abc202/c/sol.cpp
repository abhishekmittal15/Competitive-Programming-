#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a,b,c;
    int n,ans=0;
    cin>>n;
    int cnt[n+1]={0};
    for(int i=0,x;i<n;i++)
        cin>>x,a.push_back(x),cnt[x]++;
    for(int i=0,x;i<n;i++)
        cin>>x,b.push_back(x);
    for(int i=0,x;i<n;i++)
        cin>>x,c.push_back(x);
    for(int i=0;i<n;i++)
        ans+=cnt[b[c[i]-1]];
    cout<<ans<<endl;
    return 0;
}