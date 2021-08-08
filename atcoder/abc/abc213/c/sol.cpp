#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define int long long int 
signed main(){
    int h,w,n;
    cin>>h>>w>>n;
    vector<int> r(n),c(n);
    map<int, int> rows, cols;
    // Take inputs 
    // to create a map that maps each of the old rows to the new rows 
    // then to print it, we loop over the old rows and then print the new rows instead of the old rows 
    for (int i = 0;i<n;i++){
        cin >> r[i] >> c[i];
        rows[r[i]] = r[i];
        cols[c[i]] = c[i];
    }
    int missing = 0;
    int prev = 0;
    for (auto &i: rows){
        int cur = i.first;
        missing+=(cur-prev-1);
        i.second -= missing;
        // cout << i.first << " " << i.second << endl;
        prev = cur;
    }
    missing = 0;
    prev = 0;
    for (auto &i:cols)
    {
        int cur = i.first;
        missing += (cur - prev-1);
        i.second -= missing;
        prev = cur;
    }
    for (int i = 0; i < n;i++){
        cout << rows[r[i]] << " " << cols[c[i]] << endl;
    }
    return 0;
}