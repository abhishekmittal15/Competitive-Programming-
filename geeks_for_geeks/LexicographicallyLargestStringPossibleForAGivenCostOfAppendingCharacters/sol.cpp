// #include<iostream>
// #include<vector>
// using namespace std;
// #define int long long int 
// signed main(){
//     int w;
//     cin >> w;
//     vector<int> characters(26);
//     for (int i = 0; i < 26;i++)
//         cin >> characters[i];
//     string ans = "";
//     int current_letter = 25;
//     while(w>0 && current_letter>=0){
//         if(w>=characters[current_letter]){
//             ans += ('a' + current_letter);
//             w -= characters[current_letter];
//         }
//         else
//             current_letter--;
//     }
//     cout << ans << endl;
//     return 0;
// }

// This greedy solution si totally wrong as we have to find the string which has an exact weight of W, not less than or equal to W. 

#include<iostream>
#include<vector>
using namespace std;
#define int long long int
bool dfs(int i,vector<int>& cost,vector<int>& v,int w){
    if(w<0 || i<0)
        return false;
    if(w==0)
        return true;

    v.push_back(i);
    if(dfs(i,cost,v,w-cost[i]))
        return true;

    v.erase(v.end() - 1);

    return dfs(i-1,cost,v,w);
}
string solve(int w,vector<int>& cost){
    string ans = "";
    vector<int> v;
    dfs(25, cost, v, w);
    for (int i = 0; i < v.size();i++)
        ans += ('a' + v[i]);
    return ans;
} 
signed main(){
    int w;
    cin>>w;
    vector<int> characters(26);
    for (int i = 0; i < 26;i++)
        cin >> characters[i];
    string ans = solve(w, characters);
    cout << ans << endl;
}