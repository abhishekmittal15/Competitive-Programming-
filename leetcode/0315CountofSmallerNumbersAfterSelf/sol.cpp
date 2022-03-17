#include<iostream>
#include<vector>
using namespace std;
#define int long long int 

void merge(vector<pair<int,int>>& a,int l,int r,vector<int>& cnt){
        
    vector<pair<int,int>> temp;
    int mid=(l+r)/2;
    int ptr1=l;
    int ptr2=mid+1;
    int sz1=mid-l+1;
    int sz2=r-mid;
    
    int c=0;

    while(ptr1<=mid and ptr2<=r){
        if(a[ptr1].first<a[ptr2].first){
            temp.push_back(a[ptr1]);
            cnt[a[ptr1].second]+=c;
            ptr1++;
        }
        else{
            temp.push_back(a[ptr2++]);
            c++;
        }
    }
    while(ptr1<=mid){
        temp.push_back(a[ptr1]);
        cnt[a[ptr1].second]+=c;
        ptr1++;
    }
    while(ptr2<=r)
        temp.push_back(a[ptr2++]);
    for(int i=l;i<=r;i++)
        a[i]=temp[i-l];

}
    
void divide(vector<pair<int,int>>& a,int l,int r,vector<int>& cnt){

    int mid=(l+r)/2;
    if(l==r)
        return;
    divide(a,l,mid,cnt);
    divide(a,mid+1,r,cnt);
    merge(a,l,r,cnt);

}

vector<int> solve(vector<int>& a){

    int n=a.size();
    vector<pair<int,int>> temp;
    vector<int> cnt(n,0);
    for(int i=0;i<n;i++)
        temp.push_back({a[i],i});
    divide(temp,0,n-1,cnt);
    for(int i=0;i<n;i++)
        cout<<temp[i].first<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<cnt[i]<<" ";
    cout<<endl;
    return cnt;
}


signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int> cnt=solve(a);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
