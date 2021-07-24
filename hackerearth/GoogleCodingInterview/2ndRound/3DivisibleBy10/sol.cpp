#include<iostream>
#include<vector>
using namespace std;
#define int long long int
signed main(){
    int n, cnt10 = 0, cnt5 = 0, cnt2 = 0;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
        if(nums[i]%10==0)
            cnt10++;
        else if(nums[i]%5==0)
            cnt5++;
        else if(nums[i]%2==0)
            cnt2++;
    }
    int ans = (cnt10 * (n - cnt10)) + (cnt5 * cnt2)+(cnt10*(cnt10-1))/2;
    cout << ans << endl;
    return 0;
}