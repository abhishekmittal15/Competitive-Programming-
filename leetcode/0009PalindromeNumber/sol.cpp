#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
signed main(){
    int n;
    bool ans = true;
    cin>>n;
    if(n<0)
        ans = false;
    else{
        vector<int> result;
        while(n>0){
            result.push_back(n % 10);
            n /= 10;
        }
        for (int i = 0; i < result.size();i++){
            if(result[i]!=result[result.size()-i-1])
                ans = false;
        }
    }
    cout << ans << endl;
    return 0;
}