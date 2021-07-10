#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define int long long int 

bool cmp(int a,int b){
    return a > b;
}

ostream &operator<<(ostream& os,const vector<int>& a){
    for(auto i:a){
      os << i << " ";
    }
    os << endl;
    return os;
}

ostream &operator<<(ostream &os, const map<int, vector<int>> a)
{
    for (auto i : a)
    {
        int univ = i.first;
        vector<int> temp = i.second;
        cout << i.first << "->";
        for (int j = 0; j < temp.size(); j++)
        {
            os << temp[j] << " ";
        }
        os << endl;
    }
    return os;
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> u(n);
        map<int, vector<int>> students,prefix;
        for (int i = 0; i < n;i++){
            cin >> u[i];
        }
        for (int i = 0,skill; i < n;i++){
            cin >> skill;
            students[u[i]].push_back(skill);
        }
        for(auto i:students){
            int univ = i.first;
            vector<int> temp = i.second;
            sort(temp.begin(), temp.end(), cmp);
            for(auto j:temp){
                if(prefix[univ].size()==0)
                    prefix[univ].push_back(j);
                else
                    prefix[univ].push_back(prefix[univ][prefix[univ].size() - 1] + j);
            }
        }
        // for (int k = 1; k <= n;k++){
        //     int strength = 0;
        //     for(auto i:prefix){
        //         vector<int> temp = i.second;
        //         if(temp.size()<k)
        //             continue;
        //         // cout << (temp.size() / k) * k << endl;
        //         strength += (temp[(temp.size() / k) * k-1]);
        //     }
        //     cout << strength << " ";
        // }
        // cout << endl;

        vector<int> strength(n+1,0);
        for (int univ = 1; univ <= n;univ++){
            for (int k = 1; k <= prefix[univ].size();k++){
                strength[k] += prefix[univ][(prefix[univ].size() / k) * k - 1];
            }
        }
        for (int i = 1; i <= n;i++){
            cout << strength[i] << " ";
        }
        cout << endl;
    }
    return 0;
}