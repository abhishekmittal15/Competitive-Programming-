#include<iostream>
using namespace std;
#define int long long int 
bool solve(int maxChoosableInteger,int desiredTotal){
    int max_amt = desiredTotal + maxChoosableInteger ;
    bool dp[max_amt+1][2];
    for (int i = 0; i <= maxChoosableInteger;i++){
        dp[i][0] = true;
        dp[i][1] = false;
    }
    for (int i = maxChoosableInteger + 1; i <= max_amt;i++){
        bool temp = false;
        for (int j = i - maxChoosableInteger; j < i;j++){
            temp = temp | dp[j][1];
        }
        dp[i][0] = temp;
        temp = false;
        for (int j = i - maxChoosableInteger; j < i; j++)
        {
            temp = temp | dp[j][0];
        }
        dp[i][1] = temp;
    }
    for (int i = desiredTotal; i <= max_amt;i++)
        if(dp[i][0])
            return true;
    return false;
}
signed main(){
    int maxChoosableInteger, desiredTotal;
    cin >> maxChoosableInteger >> desiredTotal;
    bool ans = solve(maxChoosableInteger, desiredTotal);
    cout << "Answer : " << ans << endl;
    return 0;
}