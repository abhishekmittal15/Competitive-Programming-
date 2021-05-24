#include<bits/stdc++.h>
using namespace std;
bool present(int digit, vector<int> vec)
{
    for (int i = 0; i < vec.size();i++){
        if(vec[i]==digit)
            return true;
    }
    return false;
}
bool check(int digit1, int digit2, int digit3, int digit4,vector<int> correct ){
    int cnt = 0;
    for (int i = 0; i < correct.size();i++){
        if (digit1 == correct[i] || digit2 == correct[i] || digit3 == correct[i] || digit4 == correct[i])
            cnt++;
    }
    if(cnt==correct.size())
        return true;
    return false;
} 
int main()
{
    int ans = 0;
    string s;
    cin >> s;
    vector<int> correct, wrong;
    for (int i = 0; i < 10;i++){
        if(s[i]=='o')
            correct.push_back(i);
        else if(s[i]=='x')
            wrong.push_back(i);
    }
    int cnto = correct.size();
    if (cnto > 4)
        ans = 0;
    else{
        for (int dig1 = 0; dig1 < 10; dig1++)
        {
            if(present(dig1,wrong))
                continue;
            for (int dig2 = 0; dig2 < 10; dig2++)
            {
                if (present(dig2, wrong))
                    continue;
                for (int dig3 = 0; dig3 < 10; dig3++)
                {
                    if (present(dig3, wrong))
                        continue;
                    for (int dig4 = 0; dig4 < 10; dig4++)
                    {
                        if (present(dig4, wrong))
                            continue;
                        if(check(dig1,dig2,dig3,dig4,correct))
                            ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}