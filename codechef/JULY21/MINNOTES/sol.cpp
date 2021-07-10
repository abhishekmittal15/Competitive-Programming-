#include<iostream>
#include<algorithm>
using namespace std;
#define int long long int
int *seg;
int gcd(int a,int b){
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int findgcd(int ss,int se,int qs,int qe,int index){
    if(ss>qe || se<qs)
        return 0;
    if(ss>=qs && se<=qe)
        return seg[index];
    int mid = (ss + se) / 2;
    return gcd(findgcd(ss, mid, qs, qe, index * 2 + 1), findgcd(mid + 1, se, qs, qe, index * 2 + 2));
}
int segtree(int *a,int start,int end,int index){
    if(start==end)
        return seg[index] = a[start];
    int mid = (start + end) / 2;
    seg[index]=gcd(segtree(a, start, mid,index*2+1),segtree(a, mid + 1, end,index*2+2));
    return seg[index];
}
signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,maxgcd=-1,oddoneout=-1,ans=0;
        cin >> n;
        int a[n];
        seg = new int[4 * n];
        for (int i = 0; i < n;i++)
            cin >> a[i];
        segtree(a,0,n-1,0);
        for (int i = 0; i < n;i++){
            int currentgcd = 0;
            if(i>0)
                currentgcd = findgcd(0, n - 1, 0, i - 1, 0);
            if(i<(n-1))
                currentgcd = gcd(currentgcd, findgcd(0, n - 1, i + 1, n - 1, 0));
            if(currentgcd>maxgcd){
                maxgcd = currentgcd;
                oddoneout = i;
            }
            if(currentgcd==maxgcd){
                if(a[oddoneout]<a[i])
                    oddoneout = i;
            }
        }
        for (int i = 0; i < n;i++){
            if(i==oddoneout)
                ans++;
            else
                ans += (a[i] / maxgcd);
        }
        // cout << maxgcd << endl;
        // cout << oddoneout << endl;
        cout << ans << endl;
        delete[] seg;
    }
    return 0;
}