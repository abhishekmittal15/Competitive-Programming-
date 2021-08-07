// 3 3 3 
// 1 2 2
// 0 0 1

// 4 4 4 
// 2 3 3 
// 0 1 1 or 1 1 2
// 0 0 0

// 5 5 5 

// 1 1 1


// 5 5 2
    


// 5 6 7 
// 1 2 3  


// 5 5 10 


// no of ops=n

// x1+2x2=a // A stack 
//     x2=y1=z1
// y1+2y2=b
//     y2=x1=z1
// z1+2z2=c
//     z2=x1=y1

// x1+x2=n
// y1+y2=n
// z1+z2=n

//         n+x2=a
//         n+y2=b
//         n+z2=c

//         x2=a-n
//         y2=b-n
//         z2=c-n


#include<iostream>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        int n = (a + b + c);
        if(n%4){
            cout << "NO" << endl;
            continue;
        }
        n = n / 4;
        // cout << n << endl;
        int x2 = a - n;
        int y2 = b - n;
        int z2 = c - n;
        // cout << x2 << " " << y2 << " " << z2 << endl;
        if(x2<0 || y2<0 || z2<0){
            cout << "NO" << endl;
            continue;
        }
        int x1 = a - 2 * x2;
        int y1 = b - 2 * y2;
        int z1 = c - 2 * z2;
        // cout << x1 << " " << y1 << " " << z1 << endl;
        if (x1 < 0 || y1 < 0 || z1 < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if ((x1 == (y2+z2)) && (y1==(x2+z2)) && (z1==(x2+y2)) )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}