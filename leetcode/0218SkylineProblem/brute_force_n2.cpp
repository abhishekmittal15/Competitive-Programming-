#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
vector<vector<int>> solve(vector<vector<int>>& buildings){
    vector<vector<int>> result;
    int n = 
}
signed main(){
    int n;
    cin>>n;
    vector<int> buildings(n);
    for (int i = 0; i < n;i++){
        int left, right, height;
        cin >> left >> right >> height;
        buildings[i].push_back(left);
        buildings[i].push_back(right);
        buildings[i].push_back(height);
    }
    vector<vector<int>> outline = solve(buildings);
    for (int i = 0; i < outline.size();i++){
        cout << outline[i][0] << " " << outline[i][1] << endl;
    }
    return 0;
}