#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n ;
double dp[302][302][302];
double f(int x,int y,int z){
    if (dp[x][y][z] >= 0.0)
        return dp[x][y][z];
    if (x == 0 and y == 0 and z == 0)
        return 0.0;

    dp[x][y][z] = 0.0;

    if (x > 0)
        dp[x][y][z] += f(x - 1, y, z) * (double)(x) / (double)(x + y + z);
    if (y > 0)
        dp[x][y][z] += f(x + 1, y - 1, z) * (double)(y) / (double)(x + y + z);
    if (z > 0)
        dp[x][y][z] += f(x, y + 1, z - 1) * (double)(z) / (double)(x + y + z);

    return dp[x][y][z] = dp[x][y][z] + (double)n / (double)(x + y + z);
}
signed main(){
    memset(dp, -1.0, sizeof(dp));
    cin >> n;
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n;i++){
        int sushi;
        cin >> sushi;
        if(sushi==1)
            x++;
        else if(sushi==2)
            y++;
        else
            z++;
    }
    cout<<setprecision(100)<<f(x, y, z)<<endl;
    return 0;
}