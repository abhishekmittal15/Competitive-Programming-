#include<iostream>
#include<vector>

using namespace std;

#define int long long int 

int solve(vector<vector<int>>& grid){

    unsigned int n = grid.size();
    unsigned int m = grid[0].size();

    for (unsigned int i = 1; i < n; i++){
        for (unsigned int j = 0; j < m;j++){
            
        }
    }
}

signed main(){

    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (unsigned int i = 0; i < n;i++){
        for (unsigned int j = 0; j < m;j++){
            cin >> grid[i][j];
        }
    }

    int ans = solve(grid);
    cout << "Answer is : " << ans << endl;
    return 0;
}