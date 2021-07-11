#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
int inf=1000*1000*1000+7;
int solve(const vector<int>& nums1,const vector<int>& nums2){
    int m=nums1.size();
    int n=nums2.size();
    int start=0,end=m-1;
    while(start<=end){
        int partition1=(start+end)/2;
        int partition2=(m+n+1)/2 - partition1;

        int maxLeft1=(partition1==0)?inf:nums1[partition1-1];
        int maxLeft2=(partition2==0)?inf:nums2[partition2-1];
        int minRight1=(partition1==m-1)?-inf:nums1[partition1+1];
        int minRight2=(partition1==n-1)?-inf:nums1[partition2+1];

        if(maxLeft1>minRight2){
            end=partition1-1;
        }
        if(maxLeft2>minRight1){
            start=partition1+1;
        }
        if(maxLeft1<=minRight2 && maxLeft2<=minRight1){
            if(m+n%2==0)
                return (max(maxLeft1,maxLeft2)+min(minRight1,minRight2))/2.0;
            return max(maxLeft1,maxLeft2);
        }
    }
}
signed main(){
    vector<int> nums1,nums2;
    int m,n;
    cin>>m>>n;
    for(int i=0,a;i<m;i++)    
        cin>>a,nums1.push_back(a);
    for(int i=0,a;i<n;i++)    
        cin>>a,nums2.push_back(a);
    int ans=solve(nums1,nums2);
    cout<<"Median is : "<<ans<<endl;
    return 0;
}