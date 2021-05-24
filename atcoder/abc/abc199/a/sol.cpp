#include<iostream>
using namespace std;
bool check(int a,int b,int c){
    int temp1 = a * a + b * b;
    int temp2 = c * c;
    if(temp1<temp2)
        return true;
    return false;
}
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    string ans;
    ans = check(a, b, c) ? "Yes" : "No";
    cout << ans << endl;
    return 0;
}