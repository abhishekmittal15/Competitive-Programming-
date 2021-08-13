#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
vector<int> solve(int a[],int n,int s){
    vector<int> pref(n + 1);
    pref[0] = 0;
    for (int i= 1;i<=n;i++){
        pref[i] = pref[i - 1] + a[i - 1];
    }
    vector<int> result;
    for (int i = 1;i<=n;i++){
        int desired = pref[i] - s;
        int pos = lower_bound(pref.begin(), pref.end(),desired)-pref.begin();
        if(pref[pos]==desired){
            result.push_back(pos);
            result.push_back(i);
        }
    }
    return result;
}
signed main(){
    int n,s;
    cin>>n>>s;
    int a[n];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    vector<int> result = solve(a,n,s);
    for (int i = 0; i < 2;i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}