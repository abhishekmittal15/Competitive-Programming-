#include<iostream>
using namespace std;
#define int long long int 
int power(int a,int b,int m){
    int res=1;
    while(b>0){
        if(b&1)
            res=(res*a)%m;
        b /= 2;
        a = (a * a)%m;
    }
    return res%m;
}
signed main(){
    int t;
    cin >> t;
    while(t--){
    int m_limit;
    cin >> m_limit;
    for (int m = m_limit; m <= m_limit;m++){
        for (int n = 3; n < m;n++){
            cout<<"m:"<<m<<" n:"<<n<<endl;
            cout << "------" << endl;
            for (int i = 3; i < m;i++)
                cout << (power(i,n,m)) << " ";
            cout <<endl<<"-------" <<endl;
        }
    }
    }
    return 0;
}