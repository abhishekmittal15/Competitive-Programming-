#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int solve(vector<int>& distances, int start,int dest){
    int n = distances.size();
    int cur = start;
    int tot = 0;
    int ans = 0;
    for (int i = 0; i < n;i++)
        tot += distances[i];
    while (cur != dest)
    {
        ans += distances[cur];
        cur = (cur + 1) % n;
    }
    return min(ans,tot-ans);
}
signed main(){
    int n,start,dest;
    cin>>n>>start>>dest;
    vector<int> distances(n);
    for (int i=0; i < n;i++)
        cin >> distances[i];
    int ans = solve(distances, start, dest);
    cout << "Answer : " << ans << endl;
    return 0;
}