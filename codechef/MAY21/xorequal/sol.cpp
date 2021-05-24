#include<iostream>
using namespace std;
#define int long long int
int mod =1000 * 1000 * 1000 + 7;
int maxn= 100 * 1000 + 5;
signed main(){
    int t;
    cin>>t;
    int func[maxn];
    func[0] = 1;
    for (int i = 1; i < maxn ; i++)
    {
        int ans = func[i - 1];
        ans = ans * 2;
        ans = ans % mod;
        func[i] = ans;
    }
    while(t--){
        int n;
        cin>>n;
        int ans = func[n-1];
        cout << ans << endl;
    }
    return 0;
}