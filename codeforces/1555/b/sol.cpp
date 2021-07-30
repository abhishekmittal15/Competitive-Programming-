// touches y axis 
//     int dist=max(r1.left-r2.right,r2.left-r1.right)
//     if(dist<0)
//         dist_to_be_moved=-1*dist
// touches x axis
//     int dist=max(r1.down-r2.up,r2.down-r1.up)
//     if(dist<0)
//         dist_tobemoved=min(dist_tob-emoved,abs(dist))

#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    while(t--){
        int W, H, w, h, x1, x2, y1, y2;
        cin >> W >> H;
        cout << "input" << endl;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> w >> h;
        cout << "input" << endl;
        int ans = 1ll * 1e9;
        int dmove;
        // top left corner, i check for bottom right corner in 2nd rectangle and top left in 1st rectangle
        int hori = x1 - w;
        int verti = H - h - y2;
        cout << hori << " " << verti << endl;
        if(hori<0){
            dmove = abs(hori);
            cout << dmove << endl;
            if(x2+dmove<=W)
                ans = min(ans, dmove);
        }
        if(verti<0){
            dmove = abs(verti);
            cout << dmove << endl;
            if(y1-dmove>=0)
                ans = min(ans, dmove);
        }
        // top right corner, I check for bottom left corner in 2nd rectangle and top right corner in 1st rectangle
        hori = W-w-x2;
        verti = H - h - y2;
        cout << hori << " " << verti << endl;
        if (hori < 0)
        {
            dmove = abs(hori);
            cout << dmove << endl;
            if (x2 + dmove <= W)
                ans = min(ans, dmove);
        }
        if (verti < 0)
        {
            dmove = abs(verti);
            cout << dmove << endl;
            if (y1 - dmove >= 0)
                ans = min(ans, dmove);
        }
        // bottom right corner, I check for top left corner in 2nd rectangle and bottom right corner in 1st rectangle
        hori = W - w - x2;
        verti = y1-h;
        cout << hori << " " << verti << endl;
        if (hori < 0)
        {
            dmove = abs(hori);
            cout << dmove << endl;
            if (x2 + dmove <= W)
                ans = min(ans, dmove);
        }
        if (verti < 0)
        {
            dmove = abs(verti);
            cout << dmove << endl;
            if (y1 - dmove >= 0)
                ans = min(ans, dmove);
        }
        // bottom left corner, I check for top right corner in 2nd rectangle and bottom left corner in 1st rectangle
        hori = x1 - w;
        verti = y1-h;
        cout << hori << " " << verti << endl;
        if (hori < 0)
        {
            dmove = abs(hori);
            cout << dmove << endl;
            if (x2 + dmove <= W)
                ans = min(ans, dmove);
        }
        if (verti < 0)
        {
            dmove = abs(verti);
            cout << dmove << endl;
            if (y1 - dmove >= 0)
                ans = min(ans, dmove);
        }
        cout << ans << endl;
    }
    return 0;
}