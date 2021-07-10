#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int power(int a,int b){
    int ans = 1;
    for (int i = 0; i < b;i++)
        ans *= a;
    return ans;
}
signed main(){
    int sz = 100 * 1000 + 5;
    vector<int> chefora;
    for (int d = 1; d <=11;d++){
        for (j = d - 1; j >= d/2;j--){
            for (int i = 0; i < 10;i++){
                if(j==d-1)
                    num+
            }
        }
    }
    int q, l, r;
    cin >> q;
    while(q--){
        cin >> l >> r;
        int power_raised = prefix[r - 1] - prefix[l - 1];
        int ans = power(chefora[l], power_raised);
        cout << and << endl;
    }
    return 0;
}
