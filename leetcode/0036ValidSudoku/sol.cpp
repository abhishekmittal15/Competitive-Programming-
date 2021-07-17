#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int
bool isValidSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        vector<char> temp;
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
                temp.push_back(board[i][j]);
        }
        sort(temp.begin(), temp.end());
        for (int k = 1; k < temp.size(); k++)
            if (temp[k] == temp[k - 1])
            {
                cout << i << endl;
                return false;
            }
        temp = {};
        for (int j = 0; j < 9; j++)
        {
            if (board[j][i] != '.')
                temp.push_back(board[j][i]);
        }
        sort(temp.begin(), temp.end());
        for (int k = 1; k < temp.size(); k++)
            if (temp[k] == temp[k - 1])
                return false;
    }
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            vector<char> temp;
            for (int i = row * 3; i < row * 3 + 3; i++)
            {
                for (int j = col * 3; j < col * 3 + 3; j++)
                    if (board[i][j] != '.')
                        temp.push_back(board[i][j]);
            }
            sort(temp.begin(), temp.end());
            for (int k = 1; k < temp.size(); k++)
                if (temp[k] == temp[k - 1])
                    return false;
        }
    }
    return true;
}
signed main(){
    vector<vector<char>> board;
    for (int i = 0; i < 9;i++){
        for (int j = 0; j < 9;j++){
            cin >> board[i][j];
        }
    }
    string ans = isValidSudoku(board) ? "Yes" : "No";
    cout << ans << endl;
    return 0;
}