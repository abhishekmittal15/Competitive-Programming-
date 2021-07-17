#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int solve(vector<vector<char>>& matrix){
    int n = matrix.size();
    if(n==0)
        return 0;
    int m = matrix[0].size();
    int ans = 0;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            int startrow = i;
            int startcol = j;
            for (int k = i; k < n;k++){
                for (int l = j; l < m;l++){
                    int endrow = k;
                    int endcol = l;
                    bool allones = true;
                    for (int row = startrow; row <= endrow;row++){
                        for (int col = startcol; col <= endcol;col++){
                            if(matrix[row][col]=='0')
                                allones = false;
                        }
                    }
                    if(allones)
                        ans = max(ans, (endrow - startrow + 1) * (endcol - startcol + 1));
                }
            }
        }
    }
    return ans;
} 
signed main(){
    int rows,cols;
    cin >> rows >> cols;
    vector<vector<char>> matrix(rows, vector<char>(cols, '0'));
    for (int i = 0; i < rows;i++){
        for (int j = 0; j < cols;j++){
            cin >> matrix[i][j];
        }
    }
    int ans = solve(matrix);
    cout << "Answer : " << ans << endl;
    return 0;
}