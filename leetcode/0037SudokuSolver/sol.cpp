#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int
bool findUnassigned(vector<vector<char>>& board,int &row,int &col){
    for (row = 0; row < 9;row++){
        for (col = 0; col < 9;col++)
            if(board[row][col]=='.')
                return true;
    }
    return false;
}
bool isSafe(vector<vector<char>>& board){
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
bool solveSudoku(vector<vector<char>>& board){
    int row, col;
    if (findUnassigned(board, row, col)==false)
        return true;
    for (int num = 1; num <= 9;num++){

        board[row][col] = (char)(num+'0');
        cout << row << " " << col << " " << board[row][col] << endl;
        if(isSafe(board)){
            if(solveSudoku(board));
                return true;
        }
        board[row][col] = '.';
        cout << row << " " << col << " " << board[row][col] << endl;
    }
    return false;
}
signed main(){
    vector<vector<char>> board(9,vector<char>(9,'.'));
    for (int i = 0; i < 9;i++){
        for (int j = 0; j < 9;j++)
            cin >> board[i][j];
    }
    solveSudoku(board);
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9;j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    return 0;
}