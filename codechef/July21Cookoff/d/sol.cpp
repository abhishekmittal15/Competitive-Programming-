#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans = 0;
        int mn = 2*(1e9) + 7;
        vector<int> nums(n);
        for (int i = 0; i < n;i++){
            cin >> nums[i];
            mn = min(mn, nums[i]);
        }
        for (int i = 0;i<n;i++)
            ans += (nums[i] == mn);
        bool flag = true;
        for (int i = 0; i < n;i++){
            if(nums[i]>mn){
                if((mn>=((nums[i]+1)/2)) && mn!=0)
                    flag = false;
            }
        }
        if(flag==false)
            cout << n << endl;
        else
            cout << n - ans << endl;
    }
    return 0;
}