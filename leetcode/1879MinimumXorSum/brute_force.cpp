#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
int solve(vector<int>& nums1,vector<int>& nums2){
    int ans = 1000 * 1000 * 10 + 10;
    int n = nums1.size();
    do{
        int xor_sum = 0;
        for (int i = 0; i < n;i++)
            xor_sum += (nums1[i] ^ nums2[i]);
        for (int i = 0; i < n;i++)
            cout << nums2[i] << " ";
        ans = min(ans, xor_sum);
        cout << endl;
    } while (next_permutation(nums2.begin(), nums2.end()));
    return ans;
}
signed main(){
    int n;
    cin>>n;
    vector<int> nums1(n), nums2(n);
    for (int i = 0; i < n;i++)
        cin >> nums1[i];
    for (int i = 0; i < n; i++)
        cin >> nums2[i];
    int ans = solve(nums1, nums2);
    cout << "Answer : " << ans << endl;
    return 0;
}