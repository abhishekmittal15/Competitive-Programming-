#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int n=4;
    bool visited[] = {false, false, false, false};
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if(s=="H")
            visited[0] = true;
        if(s=="2B")
            visited[1] = true;
        if(s=="3B")
            visited[2] = true;
        if(s=="HR")
            visited[3] = true;
    }
    bool ans = true;
    for (int i = 0; i < 4;i++)
        ans = ans & visited[i];
    string str = (ans) ? "Yes" : "No";
    cout << str << endl;
    return 0;
}