#include<iostream>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    bool flag = false;
    if(a+c==2*b)
        flag = true;
    if(a+b==2*c)
        flag = true;
    if(b+c==2*a)
        flag=true;
    if(flag)
        cout<<"Yes"<<endl;
    else
        cout << "No" << endl;
    return 0;
}