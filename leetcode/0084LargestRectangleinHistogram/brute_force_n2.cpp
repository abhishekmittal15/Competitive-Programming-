#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& heights){
    int n = heights.size();
    int ans = 0;
    for (int i = 0; i < n;i++){
        int curr_ans = heights[i];
        int curr_height = heights[i];
        for (int left = i - 1; left >= 0;left--){
            if(heights[left]>=curr_height)
                curr_ans+=curr_height;
            else
                break;
        }
        for (int right = i + 1; right < n;right++){
            if(heights[right]>=curr_height)
                curr_ans +=curr_height;
            else
                break;
        }
        ans = max(ans, curr_ans);
    }
    return ans;
}
signed main(){
    int n;
    cin>>n;
    vector<int> heights(n);
    for (int i = 0; i < n;i++){
        cin >> heights[i];
    }
    int ans = solve(heights);
    cout << "Answer : " << ans << endl;
    return 0;
}