#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int> &a,vector<int> &b){
    int ans = 0;
    int n1 = a.size();
    int n2 = b.size();
    for (int i = 0;i<n1;i++){
        for (int j = 0; j < n2; j++){
            ans = max(ans, a[i] ^ b[j]);
        }
    }
    return ans;
}
signed main(){
    int n1,n2;
    cin >> n1 >> n2;
    vector<int> a(n1), b(n2);
    for (int i = 0; i < n1;i++)
        cin >> a[i];
    for (int i = 0; i < n2;i++)
        cin >> b[i];
    int ans = solve(a,b);
    cout << "Answer : " << ans << endl;
    return 0;
}