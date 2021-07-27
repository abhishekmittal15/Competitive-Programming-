#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
int solve(vector<vector<int>>& students,vector<vector<int>>& mentors){
    int m = students.size();
    int n = students[0].size();
    sort(mentors.begin(), mentors.end());
    int score = 0;
    do{
        int ans = 0;
        for (int i = 0; i < m;i++){
            for (int j = 0; j < n;j++){
                ans += (students[i][j] ^ mentors[i][j]);
            }
        }
        ans = m *n - ans;
        cout << ans << endl;
        score = max(ans, score);
    } while (next_permutation(mentors.begin(), mentors.end()));
    return score;
}
signed main(){
    int n, m;
    cin >> m>> n;
    vector<vector<int>> students(m, vector<int>(n));
    vector<vector<int>> mentors(m, vector<int>(n));
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++)
            cin >> students[i][j];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> mentors[i][j];
    }
    int score = solve(students, mentors);
    cout << "Score: " << score << endl;
    return 0;
}