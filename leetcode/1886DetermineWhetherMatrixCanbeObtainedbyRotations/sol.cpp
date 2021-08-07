#include<iostream>
#include<vector>
using namespace std;
#define int long long int
void rotate(vector<vector<int>>& mat){
    vector<vector<int>> temp;
    int n = mat.size();
    for (int col =0;col<n;col++){
        vector<int> c;
        for (int j = n-1; j >=0;j--)
            c.push_back(mat[j][col]);
        temp.push_back(c);
    }
    mat = temp;
}
bool solve(vector<vector<int>>& mat,vector<vector<int>>& target){
    for (int rot = 0; rot <= 3;rot++){
        rotate(mat);
        if(mat==target)
            return true;
    }
    return false;
}
signed main(){
    int n;
    cin>>n;
    vector<vector<int>> given(n, vector<int>(n, 0)); vector<vector<int>> target(n, vector<int>(n, 0)); for (int i = 0; i <n;i++){
        for (int j = 0;j<n;j++)
            cin >> given[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> target[i][j];
    }
    bool ans = solve(given, target);
    cout << "Answer : " << ans << endl;
    return 0;
}