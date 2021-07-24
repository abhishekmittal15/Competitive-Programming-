#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int inf = 1000 * 1000 * 1000 + 7;
int power(int a,int b){
    int ans = 1;
    while(b>0){
        if(b&1)
            ans = ans * a;
        a = a * a;
        b /= 2;
    }
    return ans;
}
vector<int> solve(int n,vector<int> nums){
    int max_masks = power(2, n);
    vector<int> dp_mx(max_masks,0);
    vector<int> dp_mn(max_masks, inf);
    dp_mx[0] = 0;
    dp_mn[0] = 0;
    vector<int> setbits;
    for (int mask = 3; mask < max_masks;mask++){
        setbits.clear();
        for (int i = 0; i < n;i++){
            if(mask&(1<<i))
                setbits.push_back(i);
        }
        if(setbits.size()%2)
            continue;
        for (int idx1 = 0; idx1 < setbits.size();idx1++){
            for (int idx2 = idx1 + 1; idx2 < setbits.size();idx2++){
                int index1 = setbits[idx1];
                int index2 = setbits[idx2];
                dp_mn[mask] = min(dp_mn[mask], (nums[index1] ^ nums[index2]) + dp_mn[mask ^ (1 << index1) ^ (1 << index2)]);
                dp_mx[mask] = max(dp_mx[mask], (nums[index1] ^ nums[index2]) + dp_mx[mask ^ (1 << index1) ^ (1 << index2)]);
            }
        }
    }
    vector<int> result;
    result.push_back(dp_mn.back());
    result.push_back(dp_mx.back());
    return result;
}
signed main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++)
        cin >> nums[i];
    vector<int> result = solve(n, nums);
    int ans_mn = result[0];
    int ans_mx = result[1];
    cout << "Smallest : " << ans_mn << endl;
    cout<<"Largest: " <<ans_mx<< endl;
    return 0;
}