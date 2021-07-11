#include<iostream>
#include<vector>
#define int long long int
using namespace std;
string simplifyPath(string path) {
    string ans="/";
    vector<string> directories;
    if(path[0]!='/')
        return "/";
    string name="";
    for(int i=1;i<path.length();i++){
        if(path[i]=='/' && i==path.length()-1)
            continue;
        if(path[i]=='/' && path[i+1]=='/'){
            i++;
            continue;
        }
        if (path[i] == '/' && path[i + 1] != '/')
        {
            directories.push_back(name), name = "";
            continue;
        }
        if (path[i] == '.' && path[i + 1] == '.')
        {
            if (directories.empty() == false)
                directories.pop_back();
            else
                return "/";
            continue;
        }
        if(path[i]=='.' && path[i+1]!='.')
            continue;
        name += path[i];
    }
    for (int i = 0; i < directories.size();i++){
        ans += directories[i];
        ans += '/';
    }
    return ans;
}
signed main(){
    string path = "";
    cin >> path;
    cout << simplifyPath(path) << endl;
    return 0;
}