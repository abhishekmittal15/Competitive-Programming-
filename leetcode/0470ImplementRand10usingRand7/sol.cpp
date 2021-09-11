#include<iostream>
#include<vector>
#include<random>
using namespace std;
#define int long long int 
int rand7(){
    return num;
}
int rand10(){
    return num;
}
vector<double> simulate(int n_sim){
    vector<double> results(11,0.0);
    for (int i = 0; i < n_sim;i++){
        int rand_num = rand10();
        results[rand_num] += 1.0;
    }
    for (int i = 1; i <= 10;i++)
        results[i]/=(double)(n_sim);
    return results;
}
ostream &operator<<(ostream& os,const vector<double>& a){
    int n = a.size();
    for (int i = 1; i <= n;i++)
        os << i << " " << a[i] << endl;
    return os;
}
signed main()
{
    int n;
    cout << "Enter the number of simulations to perform" << endl;
    vector<int> results = simulate(n);
    cout << "These are the results" << endl;
    cout << results << endl;
    return 0;
}