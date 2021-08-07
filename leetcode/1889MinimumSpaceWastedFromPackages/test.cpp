#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
signed main(){
    vector<int> a{1, 2, 3, 4, 5};
    int position = lower_bound(a.begin(), a.end(), 6) - a.begin();
    cout << position << endl;
    return 0;
}