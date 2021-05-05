#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> a;
    for (int i = 0; i < n;i++){
        vector<int> b;
        for (int j = 0,x; j < 3;j++) cin>>x, b.push_back(x);
        a.push_back(b);
    }
    for (int i = 0; i < n;i++){
        cout << a[i][0] << " " << a[i][1] << " " << a[i][0] + 1 << " " << a[i][1] + 1 << endl;
    }
    return 0;
}