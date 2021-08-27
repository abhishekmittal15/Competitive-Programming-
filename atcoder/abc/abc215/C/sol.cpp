#include<iostream>
#include<algorithm>
using namespace std;
#define int long long int 
signed main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    sort(s.begin(), s.end());
    int cnt = 0;
    do{
        cnt++;
        if(cnt==k)
            break;
    } while (next_permutation(s.begin(), s.end()));
    cout << s << endl;
    return 0;
}