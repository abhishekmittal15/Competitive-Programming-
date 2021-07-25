#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> even, odd;
        for (int i = 0; i < n;i++){
            int a;
            cin >> a;
            if(a%2)
                odd.push_back(a);
            else
                even.push_back(a);
        }
        for (int i = 0; i < even.size();i++)
            cout << even[i] << " ";
        for (int i = 0; i < odd.size();i++)
            cout << odd[i] << " ";
        cout << endl;
    }
    return 0;
}