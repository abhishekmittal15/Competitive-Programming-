#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    int max_sum = 5005;
    vector<int> prefix_sum(max_sum,0);
    for (int i = 1,j=1; j<max_sum;i+=2,j+=i)
        prefix_sum[j] = prefix_sum[j - i] +1;
    while (t--)
    {
        int s,ans=-1;
        cin >> s;
        ans = prefix_sum[s];
        if(ans==0)
            for (int i = s - 1;;i--)
                if(prefix_sum[i]!=0){
                    ans = prefix_sum[i]+1;
                    break;
                }
        cout << ans << endl;
    }
    return 0;
}