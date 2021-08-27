#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
bool check(vector<int>& a){
    int n = a.size()-1;
    for(int i=1;i<=n;i++)
        if(a[i]!=i)
            return false;
    return true;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        for (int i = 1; i <= n;i++){
            cin >> a[i];
        }
        int i = 1;
        while(check(a)==false){
            if(i%2)
                for (int j = 1;j<=(n-2);j+=2){
                    if (a[j] > a[j+1]){
                        swap(a[j], a[j + 1]);
                    }
                }
            else
                for (int j = 2; j <=(n - 1); j+=2)
                {
                    if (a[j] > a[j + 1])
                    {
                        swap(a[j], a[j + 1]);
                    }
                }
            i++;
            // cout << i << endl;
        }
        cout << i-1 << endl;
    }
}