#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
#define int long long int 
signed main(){
    int n,pr;
    cin>>n>>pr;
    vector<pair<int, int>> ranges(n);
    vector<double> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ranges[i].first >> ranges[i].second;
    }
    double sum = 0.0;
    double ans = n * (n - 1);
    for (int i = 0; i < n;i++){
        int li = ranges[i].first;
        int ri = ranges[i].second;
        int starting_multiple = ((li % pr == 0) ? (li / pr) : (li / pr + 1)) * pr;
        int ending_multiple = (ri / pr) * pr;
        int cnt = (ending_multiple - starting_multiple) / pr+1;
        if(cnt<0)
            cnt = 0;
        p[i] = (double)(cnt) / (double)(ri - li + 1);
        sum += (1-p[i]);
    }
    for (int i = 0; i < n;i++){
        ans -= ((1-p[i]) * (sum - 1+p[i]));
    }
    ans = ans / 2;
    cout <<setprecision(100)<< ans * 2000 << endl;
    return 0;
}