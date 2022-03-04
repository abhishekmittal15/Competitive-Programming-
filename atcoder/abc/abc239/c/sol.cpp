#include<iostream>
#include<vector>
using namespace std;

#define int long long int 

int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,2,-2,2,-2,-1,1};

signed main(){

    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    bool flag=false;
    vector<pair<int,int>> points1;
    vector<pair<int,int>> points2;
    for(int i=0;i<8;i++){
        points1.push_back({x1+dx[i],y1+dy[i]});
        points2.push_back({x2+dx[i],y2+dy[i]});
    }   

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(points1[i]==points2[j]){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}