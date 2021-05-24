#include<iostream>
using namespace std;
bool check_reachability(string s[3]){
    int cntx = 0, cnto = 0;
    for (int i = 0; i < 3;i++){
        for(int j=0;j<3;j++){
            if(s[i][j]=='X')
                cntx++;
            else if(s[i][j]=='O')
                cnto++;
        }
    }
    if(abs(cntx-cnto)>1)
        return false;
    return true;
}
int check_win(string s[3]){
    bool xwin = false;
    bool owin = false;
    for (int i = 0; i < 3;i++){
        int cntx = 0, cnto = 0;
        for (int j = 0; j < 3;j++){
            if (s[i][j] == 'X')
                cntx++;
            else if (s[i][j] == 'O')
                cnto++;
        }
        bool xwin_cur = (cntx == 3) ? true : false;
        bool owin_cur = (cnto == 3) ? true : false;
        if(xwin & xwin_cur)
            return 3;
        if(owin & owin_cur)
            return 3;
        xwin =xwin | xwin_cur;
        owin =owin | owin_cur;
    }
    for (int i = 0; i < 3; i++)
    {
        int cntx = 0, cnto = 0;
        for (int j = 0; j < 3; j++)
        {
            if (s[j][i] == 'X')
                cntx++;
            else if (s[j][i] == 'O')
                cnto++;
        }
        bool xwin_cur = (cntx == 3) ? true : false;
        bool owin_cur = (cnto == 3) ? true : false;
        if (xwin & xwin_cur)
            return 3;
        if (owin & owin_cur)
            return 3;
        xwin =xwin | xwin_cur;
        owin =owin | owin_cur;
    }
    {
        int cntx = 0, cnto = 0;
        for (int i = 0; i < 3;i++){
            if (s[i][i] == 'X')
                cntx++;
            else if (s[i][i] == 'O')
                cnto++;
        }
        bool xwin_cur = (cntx == 3) ? true : false;
        bool owin_cur = (cnto == 3) ? true : false;
        if (xwin & xwin_cur)
            return 3;
        if (owin & owin_cur)
            return 3;
        xwin = xwin | xwin_cur;
        owin = owin | owin_cur;
    }
    {
        int cntx = 0, cnto = 0;
        for (int i = 0; i < 3; i++)
        {
            if (s[i][2-i] == 'X')
                cntx++;
            else if (s[i][2-i] == 'O')
                cnto++;
        }
        bool xwin_cur = (cntx == 3) ? true : false;
        bool owin_cur = (cnto == 3) ? true : false;
        if (xwin & xwin_cur)
            return 3;
        if (owin & owin_cur)
            return 3;
        xwin = xwin | xwin_cur;
        owin = owin | owin_cur;
    }
    int cntx = 0, cnto = 0;
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 3;j++){
            if (s[i][j] == 'X')
                cntx++;
            else if (s[i][j] == 'O')
                cnto++;
        }
    }
    if ((xwin & owin) | (xwin & (cnto >= cntx)) | (owin & (cntx != cnto)))
        return 2;
    if(xwin | owin)
        return 1;
    return 0;
}
bool check_more_moves(string s[3]){
    bool flag = false;
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 3;j++){
            if(s[i][j]=='_')
                return true;
        }
    }
    return false;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string s[3];
        int ans = 0;
        for (int i = 0; i < 3;i++)
            cin >> s[i];
        bool reachable = check_reachability(s);
        int win = check_win(s);
        if(win==2 || reachable==false)
            ans = 3;
        else if(win==0 && reachable){
            bool flag = check_more_moves(s);
            if (flag)
                ans = 2;
            else
                ans = 1;
        }
        else if (win==1 && reachable)
            ans = 1;
        cout << ans << endl;
    }
    return 0;
}