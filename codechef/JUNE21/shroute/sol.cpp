#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int inf = 1000 * 1000 * 1000 + 7;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin >>n >> m;
        vector<int> stations(n), destinations(m), distance(n, inf);
        for (int i = 0; i < n;i++)
            cin >> stations[i];
        for (int i = 0; i < m;i++)
            cin >> destinations[i];
        distance[0] = 0;
        int nearest1 = -1;
        for (int i = 0; i < n;i++){
            if(nearest1!=-1)
                distance[i] = min(distance[i], abs(i - nearest1));
            if(stations[i]==1)
                nearest1 = i;
        }
        int nearest2 = -1;
        for (int i = n-1; i >=0 ; i--)
        {
            if (nearest2 != -1)
                distance[i] = min(distance[i], abs(i - nearest2));
            if (stations[i] == 2)
                nearest2 = i;
        }
        for (int i = 0; i < m;i++){
            int dest = destinations[i];
            int ans = distance[dest-1];
            if(ans==inf)
                ans = -1;
            if(stations[dest-1]!=0)
                ans = 0;
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}