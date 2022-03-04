#include<iostream>
#include<vector>
using namespace std;

#define int long long int 

int solve(vector<vector<int>>& intervals){

    int n=intervals.size();
    int ans=n;
    vector<bool> covered(n,false);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // We want to see if the ith interval covers the jth interval iff jth interval has not been previously covered
            if(intervals[i][0]<=intervals[j][0] and intervals[i][1]>=intervals[j][1] and covered[j]==false and i!=j){
                ans--;
                covered[j]=true;
            }
        }
    }
    return ans;
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