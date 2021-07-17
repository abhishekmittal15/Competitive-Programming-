#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int inf = 1000 * 100;
int initial = 1000 * 1000;
int power(int a,int b){
    int ans = 1;
    while(b>0){
        if(b&1)
            ans = ans * a;
        a = a * a;
        b /= 2;
    }
    return ans;
}
bool valid(vector<vector<int>> points){
    int n = points.size();
    float slope = (float)(initial);
    for (int i = 1; i < n;i++){
        float new_slope = points[i][1] - points[i-1][1];
        if (points[i][0] == points[i-1][0])
            new_slope = inf;
        else
            new_slope = new_slope / (points[i][0] - points[i-1][0]);
        if(new_slope!=slope && slope!=(float)(initial))
            return false;
        else
            slope = new_slope;
    }
    return true;
}
int solve(vector<vector<int>>& points){
    int ans = -1;
    int n = points.size();
    int max_subsets = power(2, n);
    for (int i = 0; i < max_subsets;i++){
        vector<vector<int>> temp;
        for (int j = 0; j < n;j++){
            if(i&(1<<j)){
                temp.push_back(points[j]);
            }
        }
        if(valid(temp))
            // cout << "Hey" << endl;
            ans = max(ans, (int)(temp.size()));
    }
    return ans;
}
signed main(){
    int n;
    cin>>n;
    vector<vector<int>> points(n);
    for (int i = 0; i < n;i++){
        int x, y;
        cin >> x >> y;
        points[i].push_back(x);
        points[i].push_back(y);
    }
    int answer = solve(points);
    cout << "Answer is " << answer << endl;
    return 0;
}