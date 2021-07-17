#include<iostream>
#include<vector>
using namespace std;
#define int long long int 
vector<int> solve(vector<int>& arr){
    int n=arr.size();
    int cnt1 = 0;
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==1)
            cnt1++;
    }
    if(cnt1==0){
        result.push_back(0);
        result.push_back(n-1);
        return result;
    }
    if(cnt1%3!=0){
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
    int num1 = cnt1 / 3;
    int break1 = -1, break2 = -1;
    int cnt1_part1 = 0;
    int cnt1_part2 = 0;
    int cnt1_part3 = 0;
    int cnt0_part1 = 0;
    int cnt0_part2 = 0;
    int cnt0_part3 = 0;
    for (int i = 0; i < n;i++){
        if(arr[i]==1)
            cnt1_part1++;
        if(cnt1_part1==num1){
            break1 = i;
            break;
        }
    }
    cout << "Initially Break1 is " << break1 << endl;
    for (int i = n - 1; i >= 0;i--){
        if(arr[i]!=0)
            break;
        cnt0_part3++;
    }
    cout << "number of zeros to the end of the number should be " << cnt0_part3 << endl;
    for (int i = n - 1; i >= 0;i--){
        if(arr[i]==1){
            cnt1_part3++;
        }
        if(cnt1_part3==num1){
            break2 = i - 1;
            break;
        }
    }
    cout << "Initially break 2 is " << break2 << endl;
    int new_break1 = break1;
    for (int i = break1 + 1; i <= break1 + cnt0_part3; i++)
    {
        if(arr[i]!=0){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        new_break1 = i;
    }
    break1 = new_break1;
    cout << "Updated Break1 is " << break1 << endl;
    int new_break2 = break2;
    for (int i = break1 + 1;; i++)
    {
        if(arr[i]==1)
            cnt1_part2++;
        if(cnt1_part2==num1){
            new_break2 = i;
            break;
        }
    }
    if(cnt1_part2!=num1){
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
    cout << "New break 2 is " <<new_break2<< endl;
    cnt0_part2 = break2 - new_break2;
    cout << " Number of trailing zeros in part 2 is " << cnt0_part2 << endl;
    if(cnt0_part2<cnt0_part3){
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
    break2 = new_break2 + cnt0_part3;
    cout << "Updated break2 is " << break2<< endl;
    vector<int> numb1, numb2, numb3;
    bool one_has_occurred = false;
    for (int i = 0; i <=break1;i++){
        if(arr[i]==0){
            if(one_has_occurred)
                numb1.push_back(arr[i]);
            else
                continue;
        }
        else{
            numb1.push_back(arr[i]);
            one_has_occurred = true;
        }
    }
    one_has_occurred = false;
    for (int i = break1 + 1; i <= break2;i++){
        if (arr[i] == 0)
        {
            if (one_has_occurred)
                numb2.push_back(arr[i]);
            else
                continue;
        }
        else
        {
            numb2.push_back(arr[i]);
            one_has_occurred = true;
        }
    }
    one_has_occurred = false;
    for (int i = break2 + 1; i < n; i++)
    {
        if (arr[i] == 0)
        {
            if (one_has_occurred)
                numb3.push_back(arr[i]);
            else
                continue;
        }
        else
        {
            numb3.push_back(arr[i]);
            one_has_occurred = true;
        }
    }
    if(numb1.size()==numb2.size() && numb2.size()==numb3.size()){
        for (int i = 0; i < numb1.size();i++)
        {
            if(numb1[i]==numb2[i] && numb2[i]==numb3[i])
                continue;
            else{
                result.push_back(-1);
                result.push_back(-1);
                return result;
            }
        }
    }
    else{
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
    result.push_back(break1);
    result.push_back(break2+1);
    return result;
}
signed main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ans=solve(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}