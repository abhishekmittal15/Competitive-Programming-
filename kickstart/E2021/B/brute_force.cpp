#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int tests;
    cin>>tests;
    for (int t = 1; t <= tests;t++){
        int r, c, r1, r2, c1, c2,k;
        cin >> r >> c >> k>>r1 >> c1 >> r2 >> c2;
        int up = c2 - c1 + 1;
        int down = c2 - c1 + 1;
        int right = r2 - r1 + 1;
        int left = r2 - r1 + 1;
        int perimeter = left + down + right + up;
        if(r1==1)
            perimeter -= up;
        if(r2==r)
            perimeter -= down;
        if(c1==1)
            perimeter -= left;
        if (c2 == c)
            perimeter -= right;
        int ans = min(min(r1-1, r - r2 ), min(c1-1, c - c2)) + perimeter+(r2-r1)*(c2-c1+1)+(c2-c1)*(r2-r1+1);
        cout << "Case #" << t << ": " << ans << endl;
    }
}