#include<iostream>
#include<vector>
using namespace std;

#define int long long int 

bool check(vector<int>& a,int k,int target_sum){

    int current_sum=0;
    int n=a.size();
    for(int i=0;i<n;i++){
        current_sum+=a[i];
        if(current_sum>target_sum){
            current_sum=a[i];
            k--;
        }
    }
    return k>0;
}

int solve(vector<int>& a,int k){

    int n=a.size();
    int start=1;
    int end=1e15;
    int ans=-1;
    while(start<=end){

        int current_sum=(start+end)/2;
        cout<<start<<" "<<end<<" "<<current_sum<<endl;
        if(check(a,k,current_sum)){
            ans=current_sum;
            end=current_sum-1;
        }
        else{
            start=current_sum+1;
        }
    }
    return ans;
}

signed main(){

    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int answer=solve(a,k);
    cout<<answer<<endl;
    return 0;

}