#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin>>n;
    vector<int> cnt(3, 0);
    for (int i = 0;i<n;i++){
        int a;
        cin>>a;
        cnt[a]++;
    }
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < cnt[i];j++)
            cout <<i << " ";
    }
    cout << endl;
    return 0;
}