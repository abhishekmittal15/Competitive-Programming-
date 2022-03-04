#include<iostream>
#include<set>
#include<vector>
#include<climits>
using namespace std;

#define int long long int 

int solve(vector<int>& nums){

    int n=nums.size();
    set<int> pq;
    for(int i=0;i<n;i++){
        if(nums[i]%2)
            pq.insert(2*nums[i]);
        else    
            pq.insert(nums[i]);
    }

    bool flag=true;
    int global_min=INT_MAX;
    while(flag){
        int max_element=*pq.rbegin();
        int min_element=*pq.begin();
        int curr_min=max_element-min_element;
        global_min=min(curr_min,global_min);
        if(max_element%2)
            flag=false;
        else{
            pq.erase(max_element);
            max_element/=2;
            pq.insert(max_element);
        }
    }
    return global_min;

}

signed main(){

    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int answer=solve(nums);
    cout<<answer<<endl;
    return 0;
    
}