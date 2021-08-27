#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
#define int long long int 
double power(int n,int i){
    double ans = 1.0;
    for (int ptr = 0; ptr < i;ptr++)
        ans = ans * n;
    return ans;
}
double ncr(int n,int r){
    if(r==1)
        return (double)(n)*1.0;
    if(r==2)
        return (double)(n * (n - 1)) / 2.0;
    if(r==3)
        return (double)(n * (n - 1) * (n - 2)) / 6.0;
}
signed main(){
    int n;
    cin>>n;
    double precision = 1e-9;
    vector<int> cnt(4);
    vector<double> ans(4);
    for (int i = 0; i < n;i++){
        int sushis;
        cin >> sushis;
        cnt[sushis]++;
    }
    for (int i = 1; i <= 1;i++){
        ans[i] = 0.0;
        int x = -1;
        double cur_ans = 0.0;
        double n_term = 1.0 / power(n, i);
        while(x++){
            double additional = ncr(i + x, i);
            n_term = n_term * (double)(n - 1);
            n_term /= (double)(n);
            additional *= n_term;
            cout << additional << endl;
            cur_ans = (double)(i+x)*(ans[i] + additional);
            if((cur_ans-ans[i])<precision)
                break;
            ans[i] = cur_ans;
        }
    }
    double final = 0.0;
    // for (int i = 1; i <= 3;i++)
    //     cout << i<<" "<<ans[i] << endl;
    for (int i = 1; i <= 3; i++)
    {
        final += (cnt[i] * ans[i]);
    }
    // cout << setprecision(100) << final << endl;
    return 0;
}