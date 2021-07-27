#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
vector<int> solve(vector<int>& heights){
    vector<int> result;
    int n = heights.size();
    result.push_back(0);
    for (int i = n - 2; i >= 0;i--){
        int ans = lower_bound(heights.begin() + i+1, heights.end(), heights[i])-heights.begin();
        if(ans==n)
            ans--;
        cout << ans << endl;
        result.push_back(ans - i);
        cout << ans - i << endl;
    }
    return result;
}
signed main(){
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n;i++)
        cin >> heights[i];
    vector<int> ans = solve(heights);
    for (int i = 0; i < n;i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
