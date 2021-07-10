#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int f(vector<int> temp){
    int sum = 0;
    for (int i = 0; i < temp.size();i++){
        temp[i] = temp[i] + *max_element(temp.begin(), temp.end());
        sum = sum + temp[i];
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    vector<int> temp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        temp.push_back(a[i]);
        cout<<f(temp)<<endl;
    }
    return 0;
}