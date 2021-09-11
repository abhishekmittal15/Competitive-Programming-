#include<iostream>
#include<map>
using namespace std;
#define int long int
signed main(){
    map<string, bool> present;
    present["ABC"] = false;
    present["AHC"] = false;
    present["AGC"] = false;
    present["ARC"] = false;
    for (int i = 0; i < 3;i++){
        string s;
        cin>>s;
        present[s] = true;
    }
    for (auto i:present){
        if(i.second==false)
            cout << i.first << endl;
    }
    return 0;
}