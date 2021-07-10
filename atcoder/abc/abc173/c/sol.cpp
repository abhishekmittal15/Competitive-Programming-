#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
ostream& operator<<(ostream& os,const vector<int>& a ){
    for (int i = 0; i < a.size();i++)
        os << a[i];
    os << endl;
    return os;
}
int power(int a,int b){
    int ans = 1;
    for (int i = 0;i<b;i++)
        ans = ans * a;
    return ans;
}
signed main(){
    int h, w, k,black=0,cnt=0;
    cin >> h >> w >> k;
    string s[h];
    for (int i = 0; i < h;i++){
        cin >> s[i];
        for (int j = 0; j < w;j++)
            if(s[i][j]=='#')
                black++;
    }
    int rowsMax = power(2, h);
    int colsMax = power(2, w);
    for (int rows = 0; rows < rowsMax;rows++){
        vector<int> rows_red;
        // cout << "current rows -------" << endl;
        for (int i = 0; i < h;i++)
            if(rows&(1<<i))
                rows_red.push_back(i);
        // cout << rows_red;
        for (int cols = 0; cols < colsMax;cols++){
            int ans = 0;
            vector<int> cols_red;
            for (int i = 0; i < w;i++)
                if(cols & (1<<i))
                    cols_red.push_back(i);
            // cout << cols_red;
            bool map[h + 1][w + 1];
            for(auto i:rows_red){
                for (int j = 0; j < w;j++)
                    if(s[i][j]=='#'){
                        ans++;
                        map[i][j] = true;
                    }
            }
            for(auto j:cols_red){
                for (int i = 0;i<w;i++)
                    if(s[i][j]=='#')
                        if(map[i][j]==false)
                            ans++;
            }
            // cout << ans << endl;
            if(black-ans==k)
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}