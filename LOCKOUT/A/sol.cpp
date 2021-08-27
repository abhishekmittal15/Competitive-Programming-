#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int
signed main(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> f(n+1);
    for (int i = 1; i <=n;i++)
        cin>>f[i];
    vector<int> current_list(k);
    while(q--){
        int type,id;
        cin>>type;
        cin >> id;
        if(type==1){
            current_list.push_back(f[id]);
            sort(current_list.begin(), current_list.end());
            if(current_list.size()>k)
                current_list.erase(current_list.begin());
        }
        else{
            bool flag = false;
            for (int i = 0; i < k;i++)
                if(current_list[i]==f[id])
                    flag = true;
            if(flag)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}