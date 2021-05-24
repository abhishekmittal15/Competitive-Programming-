#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first > b.first;
}
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> heights;
    vector<string> names;
    for (int i = 0; i < n;i++){
        int height = 0;
        string name;
        cin >> name >> height;
        names.push_back(name);
        heights.push_back(make_pair(height,i));
    }
    sort(heights.begin(), heights.end(), cmp);
    cout << names[heights[1].second] << endl;
    return 0;
}