#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin >> n;
    vector<string> first(n);
    vector<string> last(n);
    for (int i = 0; i < n;i++){
        cin >> first[i] >>last[i];
    }
    for (int i = 0; i < n;i++){
        for (int j = i+1; j < n;j++){
            if(first[i]==first[j] && last[i]==last[j]){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}