#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define int long long int 

signed main(){

    int n,m;
    cin >> n >>m;
    map<string, bool> stations;
    vector<string> stations_list;
    for (int i = 0; i < n;i++){
        string station;
        cin >> station;
        stations_list.push_back(station);
        stations[station] = false;
    }

    for (int i = 0;i<m;i++){
        string station;
        cin>>station;
        stations[station] = true;
    }

    for (int i = 0;i<n;i++){
        string ans="No";
        if(stations[stations_list[i]])
            ans="Yes";
        cout<<ans<<endl;
    }
    return 0;
}
