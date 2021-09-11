#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
vector<int> a;
int n, k, z;
int f(int pos,int rem,bool can_go_left,int remleft){
    int score=a[pos];
    int mx = 0;
    cout << pos << endl;
    if(rem==0)
        return score;
    if(can_go_left && pos>0 && remleft>0){
        mx = f(pos - 1, rem - 1, false, remleft - 1);
    }
    if(pos<(n-1))
        mx = max(mx, f(pos + 1, rem - 1, true, remleft));
    return score + mx;
}
signed main(){
    cin>>n>>k>>z;
    a.clear();
    a.resize(n);
    for (int i = 0;i<n;i++)
        cin >> a[i];
    cout << f(0, k, false, z) << endl;
    return 0;
}