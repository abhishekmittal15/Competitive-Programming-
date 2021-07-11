#include<iostream>
#include<vector>
using namespace std;
#define int long long int
double solve(const vector<int>& nums1,const vector<int>& nums2){
    int m = nums1.size();
    int n = nums2.size();
    vector<int> result;
    int index1 = 0, index2 = 0;
    while(index1<m && index2<n){
        if(nums1[index1]<nums2[index2])
            result.push_back(nums1[index1++]);
        else
            result.push_back(nums2[index2++]);
    }
    while(index1<m){
        result.push_back(nums1[index1++]);
    }
    while (index2 < n)
    {
        result.push_back(nums2[index2++]);
    }
    if((m+n)%2==0)
        return (double)(result[(m + n) / 2] + result[(m + n) / 2 - 1]) / 2.0;
    return result[(m + n) / 2];
}
signed main(){
    vector<int> nums1, nums2;
    int m, n;
    cin >> m >> n;
    for (int i = 0,a; i < m;i++)
        cin >> a, nums1.push_back(a);
    for (int i = 0, a; i < n; i++)
        cin >> a, nums2.push_back(a);
    double median = solve(nums1, nums2);
    cout << "Median is : " << median << endl;
    return 0;
}