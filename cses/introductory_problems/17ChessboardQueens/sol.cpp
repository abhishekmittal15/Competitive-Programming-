#include<iostream>
#include<vector>
using namespace std;
string board[8];
int ans = 0;
vector<bool> takencols(8), takendiag1(15), takendiag2(15);
void rec(int row){
    if(row==8){
        ans++;
        return;
    }
    for (int col = 0; col < 8;col++){
        if(takencols[col]==false && takendiag1[row-col+8-1]==false && takendiag2[row+col]==false && board[row][col]=='.'){
            takencols[col] = true;
            takendiag1[row - col + 8 - 1] = true;
            takendiag2[row +col] = true;
            rec(row + 1);
            takencols[col] = false;
            takendiag1[row - col + 8 - 1] = false;
            takendiag2[row + col] = false;
        }
    }
}
int main(){
    int n=8,m=8;
    for(int i=0;i<n;i++)
        cin>>board[i];
    rec(0);
    cout << ans << endl;
}