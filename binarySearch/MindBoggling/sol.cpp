#include<iostream>
#include<vector>
using namespace std;
#define int long long int 

bool recurse(vector<vector<string>>& grid,int row,int col,int pos,string cur_word,vector<vector<bool>>& visited){

    int len=cur_word.length();
    int n=grid.size();
    int m=grid[0].size();
    if(len==pos){
        return true;
    }
    visited[row][col]=true;
    if(cur_word[pos]=grid[row][col][0])
        return false;
    bool ans=false;
    if(row>0){
        ans=ans|recurse(grid,row,col-1,pos+1,cur_word,visited);
    }
    if(row<n-1){
        ans=ans|recurse(grid,row,col+1,pos+1,cur_word,visited);
    }
    if(col>0){
        ans=ans|recurse(grid,row-1,col,pos+1,cur_word,visited);
    }
    if(col<m-1){
        ans=ans|recurse(grid,row+1,col,pos+1,cur_word,visited);
    }
    return ans;
}

int solve(vector<vector<string>>& grid,vector<string>& list_words){

    int cnt=0;
    int n=grid.size();
    int m=grid[0].size();
    int num_words=list_words.size();
    for(int i=0;i<num_words;i++){
        bool flag=false;
        string cur_word=list_words[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(flag)
                    continue;
                vector<vector<bool>> visited(n,vector<bool>(m,false));
                string current_char=grid[i][j];
                if(current_char[0]==cur_word[0]){
                    bool word_found=recurse(grid,i,j,0,cur_word,visited);
                    if(word_found){
                        cnt++;
                        flag=true;
                    }
                }
            }
        }

    }
    return cnt;
}


signed main(){

    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int num_words=0;
    vector<string> list_words(num_words);
    for(int i=0;i<num_words;i++){
        cin>>list_words[i];
    }

    int answer=solve(grid,list_words);
    cout<<answer<<endl;
    return 0;

}