#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define int long long int

ostream &operator<<(ostream &os, const map<int, vector<int>> a)
{
    for(auto i:a){
        int univ = i.first;
        vector<int> temp = i.second;
        cout << i.first << "->";
        for (int j = 0; j < temp.size();j++){
            os << temp[j] << " ";
        }
    }
    return os;
}
signed main(){
    int n;
    cin >> n;
    map<int, vector<int>> students;
    students[1].push_back(1);
    students[1].push_back(2);
    students[2].push_back(3);
    // for (int i = 0; i < 3;i++){
    //     int n = students[i].size();
    //     for (int j = 0; j < n;j++){
    //         cout << students[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << students << endl;
    return 0;
}