#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long int 

signed main(){

    int n;
    cin>>n;
    vector<vector<int>> affinity(2*n,vector<int>(2*n,0));
    for (int i = 0; i < 2 * n - 1;i++){
        for (int j = i + 1;j < 2 * n;j++){
            cin >> affinity[i][j];
        }
    }
    vector<int> indices;
    for(int i=0;i<2*n;i++){
        indices.push_back(i);
    }
    int ans=0;
    do{
        int fun=0;
        for(int i=0;i<2*n;i+=2){
            int person1=indices[i];
            int person2=indices[i+1];
            fun=fun^(affinity[min(person1,person2)][max(person1,person2)]);
        }
        ans=max(ans,fun);
    }while(next_permutation(indices.begin(),indices.end()));
    cout<<ans<<endl;
    return 0;
}