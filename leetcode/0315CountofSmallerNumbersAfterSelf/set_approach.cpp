// CPP program to find count of smaller
// elements on right side using set in C++
// STL.
#include<iostream>
#include<set>
#include<vector>
using namespace std;
vector<int> countSmallerRight(vector<int>& nums)
{
    set<int> s;
    int n = nums.size();
    vector<int> countSmaller(n);
    for (int i = n - 1; i >= 0; i--)
    {
        s.insert(nums[i]);
        auto it = s.lower_bound(nums[i]);
        countSmaller[i] = distance(s.begin(), it);
    }
    return countSmaller;
}

// Driver code
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++)
        cin >> nums[i];
    vector<int> ans=countSmallerRight(nums);
    for (int i = 0; i < n;i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
