#include<iostream>
#include<vector>
using namespace std;
// #define int long long int 
int power(int a,int b){
    int ans = 1;
    for (int i = 1; i <= b;i++){
        ans = ans * a;
    }
    return ans;
}
signed main(){
    int n;
    cin >> n;
    int cnt = power(2, n);
    vector<bool> visited(cnt,false);
    int cur = 0;
    while(cnt--){
        visited[cur] = true;
        for (int i = n-1; i >=0;i--){
            cout << (bool)(cur & (1 << i));
        }
        cout << endl;
        for (int i = 0; i < n;i++){
            if(visited[cur^(1<<i)])
                continue;
            else{
                cur = cur ^ (1 << i);
                break;
            }
        }
    }
    return 0;
}