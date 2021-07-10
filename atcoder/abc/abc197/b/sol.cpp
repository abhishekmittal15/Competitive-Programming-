#include<iostream>
using namespace std;
int main(){
    int h,w,x,y,ans=1;
    cin>>h>>w>>x>>y;
    string s[h];
    for(int i=0;i<h;i++)
        cin>>s[i];
    for (int i = x; i < h && s[i][y - 1] != '#'; i++)
        ans++;
    // cout << ans << endl;
    for (int i = x - 2; i >= 0 &&  s[i][y - 1] != '#'; i--)
        ans++;
    // cout << ans << endl;
    for (int i = y; i < w && s[x - 1][i] != '#'; i++)
        ans++;
    // cout << ans << endl;
    for (int i = y - 2; i >= 0 &&  s[x - 1][i] != '#'; i--)
        ans++;
    cout<<ans<<endl;
    return 0;
}