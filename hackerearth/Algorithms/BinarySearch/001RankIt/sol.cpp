#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int 
signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n;i++)
        cin>>a[i];
    sort(a.begin(), a.end());
    int q;
    cin >> q;
    while(q--){
        int x;
        cin>>x;
        int start = 0;
        int end = n - 1;
        int mid = 0;
        while(start<=end){
            mid=(start+end)/2;
            if(a[mid]==x)
                break;
            if(a[mid]<x)
                start = mid + 1;
            else
                end=mid-1;
        }
        cout << mid +1<< endl;
    }
    return 0;
}