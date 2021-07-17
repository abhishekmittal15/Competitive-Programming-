#include<iostream>
#include<map>
using namespace std;
#define int long long int 
signed main(){
    map<string, pair<int,int>> cnt;
    cnt[""] = {1, -1};
    cnt["ab"] = {0, 11};
    for (auto i = cnt.begin(); i != cnt.end();i++)
        cout << i->first << " " << i->second.first<<" " << i->second.second << endl;
    return 0;
}