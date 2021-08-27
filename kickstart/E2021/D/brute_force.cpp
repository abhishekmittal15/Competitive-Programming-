#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
#define int long long int 
signed main(){
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests;t++){
        int n;
        cin>>n;
        vector<int> cards;
        vector<int> fact(11);
        fact[0] = 1;
        for (int i = 1; i <= 10;i++)
            fact[i] = fact[i - 1] * i;
        for (int i = 0; i < n; i++)
        {
            cards.push_back(i);
        }
        double ans = 0.0;
        do{
            int current = cards[0];
            ans += 1.0;
            for (int i = 1; i < n;i++){
                if(cards[i]>current){
                    ans+=1.0;
                    current = cards[i];
                }
            }
        } while (next_permutation(cards.begin(), cards.end()));
        ans /= (double)(fact[n]);
        cout <<"Case #"<<t<<": "<< setprecision(100)<<ans << endl;
    }
}