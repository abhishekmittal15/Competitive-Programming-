#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for (int i = 0; i < t;i++){
        int n, m, k;
        cin >> n >> m >> k;
        int p[n];
        for (int i = 0; i < n;i++){
            cin >> p[i];
        }
        if(m==n){
            cout << "YES" << endl;
            continue;
        }
        int start = p[0];
        sort(p, p + n);
        int cnt=1;
        if(p[m]==start){
            if (p[m] == p[m - 1])
                cout << "MAYBE" << endl;
            else{
                cout << "NO" << endl;
            }
        }
        else if(p[m]<start){
            cout<<"NO"<<endl;
        }
        else{
            cout << "YES" << endl;
        }

    }
    return 0;
}