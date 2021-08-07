#include<iostream>
#include<map>
using namespace std;
#define int long long int 
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n, x, y, k;
        cin>>n>>x>>y>>k;
        map<int, int> m;
        for (int i = 0;i<n;i++){
            int a;
            cin>>a;
            m[a]++;
        }
        bool flag = true;
        int ptr = x;
        int cnt = y-x+1;
        for(auto i:m){
            if(i.first>=x && i.first<=y)
                if(i.second>0)
                    cnt--;
        }
        cnt = min(cnt, k);
        // cout << cnt << endl;
        int dup_cnt = cnt;
        for (auto i = m.begin(); i != m.end();i++)
        {
            if(i->second>1){
                int duplicates = i->second - 1;
                // cout << i->first << " has " << duplicates <<" "<<cnt<< endl;
                i->second = duplicates-cnt;
                if(i->second>=0){
                    cnt = 0;
                    i->second++;
                    break;
                }
                i->second = 1;
                cnt -= (duplicates);
            }
        }
        int ans = 0;
        for(auto i:m)
            if(i.second>0){
                ans++;
                // cout<<i.first<<" "<<i.second<<endl;
            }
        ans += (dup_cnt - cnt);
        cout << ans << endl;
    }
    return 0;
}