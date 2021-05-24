#include<iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='9')
            cout<<6;
        else if(s[i]=='6')
            cout<<9;
        else
        cout<<s[i];
    }
    return 0;
}