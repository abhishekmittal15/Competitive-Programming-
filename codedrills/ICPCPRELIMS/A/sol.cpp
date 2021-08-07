// [1,2,5] [3,6] [4] 

// 5+6
// 5+6
// 3+6

// 1,2,5,3,6,4
// 1 1 

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define int long long int
priority_queue<int,vector<int>,greater<int>> sz;
int brk(vector<int>& a){
    int n = a.size();
    int siz = 1;
    int cost = 0;
    for (int i = 0; i < (n-1);i++){
        if(a[i+1]<a[i]){
            cost+=;
            sz.push(siz);
            siz = 1;
        }
        else
            siz++;
    }
    sz.push(siz);
    return cost;
}
signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        int ans = 0;
        cin>>n;
        int temp;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            int val;
            for (int j = 0; j < temp; j++)
            {
                cin >> val;
                arr[i].push_back(val);
            }
            ans += brk(arr[i]);
            cout << brk(arr[i]) << endl;
        }
        while(sz.empty()==false){
            int sz1 = sz.top();
            sz.pop();
            if (sz.empty())
                break;
            int sz2 = sz.top();
            sz.pop();
            ans += (sz1 + sz2);
            sz.push(sz1 + sz2);
        }
        cout << ans << endl;
    }
    return 0;
}

1 2 3 5 6 7 1 2 5 3

 