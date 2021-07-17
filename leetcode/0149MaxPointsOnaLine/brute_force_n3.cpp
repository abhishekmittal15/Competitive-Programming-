#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int inf = 1000 * 1000;
float slope(vector<int> point1,vector<int> point2){
    float slope = point2[1] - point1[1];
    if(point1[0]==point2[0])
        return inf;
    slope = slope / (point2[0] - point1[0]);
    return slope;
}
int solve(vector<vector<int>>& points){
    int n = points.size();
    int ans = 0;
    for (int i = 0; i < n;i++){
        for (int j = i+1; j < n;j++){
            float slope_ij = slope(points[i], points[j]);
            int cnt = 2;
            for (int k = 0; k < n;k++){
                if(k==i || k==j)
                    continue;
                if(slope(points[k],points[j])==slope_ij)
                    cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    if(n==1)
        ans = 1;
    if(n==2)
        ans = 2;
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
