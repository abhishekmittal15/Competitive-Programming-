#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long int 

int solve(vector<vector<int>>& intervals){

    int n=intervals.size();
    int answer=n;
    sort(intervals.begin(),intervals.end());
    for(int i=0;i<n;i++)
        cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
    return 0;
}

signed main(){

    int n;
    cin>>n;
    vector<vector<int>> intervals(n,vector<int>(2,0));
    for(int i=0;i<n;i++){

        cin>>intervals[i][0]>>intervals[i][1];

    }
    int answer=solve(intervals);
    cout<<answer<<endl;
    return 0;

}