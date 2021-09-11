// babaa
// 1 1 0

// babbaa

// ba bba a
// bab ba a

// n+1

// aaa

// bababa


// 1+1 * 1+1

// ba ba ba 
// ba bab a
// bab a ba 
// bab ab a


#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    string s;
    cin >> s;
    int cnta = 0,ans=0;
    int n = s.length();
    for (int i = 0; i < n;i++)
        if(s[i]=='a')
            cnta++;
    if(cnta%3)
        ans = 0;
    else{
        int ptr = 0;
        int cnt1 = 0, cnt2 = 0;
        bool flag1 = false, flag2 = false;
        int last1a = 0, last2a = 0;
        for (int i = 0; i < n;i++){
            
        }
        cout << cnt1 << " " << cnt2 << endl;
        ans = ((cnt1 + 1) * (cnt2 + 1));
    }
    cout << ans << endl;
    return 0;
}