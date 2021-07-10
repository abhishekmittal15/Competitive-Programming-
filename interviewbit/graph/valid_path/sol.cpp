#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

int dx[] = {1,-1,0,0,1,-1,1,-1};
int dy[] = {0,0,1,-1,1,1,-1,-1};

double dist(int a,int b,int c,int d){
    double ans = (c - a) * (c - a) + (d - b) * (d - b);
    return sqrt(ans);
}

bool within(int x,int y,int r,const vector<pair<int,int>>& circles){
    int n = circles.size();
    for (int i = 0; i < n;i++){
        double distance = dist(x, y, circles[i].first, circles[i].second);
        if(distance<=(double)r)
            return true;
    }
    return false;
}

bool solve(int x, int y, int r, int n, const vector<pair<int, int>>& circles){
    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<vector<bool>> visited(x + 1, vector<bool>(y + 1, false));
    visited[0][0] = true;
    while(q.empty()==false){
        pair<int, int> current = q.front();
        visited[current.first][current.second] = true;
        // cout << current.first << " " << current.second << endl;
        q.pop();
        if(within(current.first,current.second,r,circles))
            continue;
        if(current.first==x && current.second==y)
            return true;
        for (int i = 0; i < 8;i++){
            int nextx = current.first + dx[i];
            int nexty = current.second + dy[i];
            if(nextx<0 || nextx>x || nexty<0 || nexty>y || visited[nextx][nexty]==true)
                continue;
            q.push({nextx, nexty});
        }
    }
    return false;
} 

int main()
{
    int x,r, y, n;
    cin >> x >> y >> n >> r;
    vector<pair<int, int>> circles(n);
    for (int i = 0; i < n;i++){
        cin >> circles[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> circles[i].second;
    }
    bool flag = solve(x, y, r, n, circles);
    string ans = flag ? "YES" : "NO";
    cout << ans << endl;
    return 0;
}