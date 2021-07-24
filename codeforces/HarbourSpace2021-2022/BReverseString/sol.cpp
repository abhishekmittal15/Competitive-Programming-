#include<bits/stdc++.h>
#define str string
#define dbl double
#define ll long long int
#define ull unsigned long long
#define vl vector<ll> 
#define vs vector<str>
#define pll pair<ll,ll> 
#define vll vector<pll>
#define sl set<ll>
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define BS binary_search
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
#define fr(i,a,b) for(long long i=a; i<b; i++)
#define nfr(i,a,b) for(long long i=a; i<=b; i++)
#define psl pair<str,ll>
#define pls pair<ll,str>
#define pss pair<str,str>
#define lcm(a,b) (a*b)/__gcd(a,b)
#define ALL(a) a.begin(),a.end()
#define stl stack<ll>
#define coml complex<ll>
#define INF 0x3f3f3f3f3f3f3f3f
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define read(v,n) fr(i,0,n)cin>>v[i]
#define print(x) fr(i,0,x.size())cout<<x[i]<<" ";cout<<"\n"
const ll N = 1002;
const ll mod = 1e9 + 7;
using namespace std;
void solve(){
    str s,t; 
    cin>>s>>t;
    if(s==t){
        cout<<"YES\n";
        return;
    }
    ll pos=0;
    for(ll i=0; i<s.size(); i++)
        if(s[i]==t[0]){
            pos=i; 
            break;
    }
    map<char,ll> mp;
    for(ll i=0; i<t.size(); i++)
        mp[t[i]]++;
    for(ll i=pos; i<s.size(); i++){
        if(mp[s[i]]){
            mp[s[i]]--;
            pos=i;
        }
    }
    for(ll i=pos-1; i>=0; i--){
        if(mp[s[i]])mp[s[i]]--;
    }
    for(char ch='a'; ch<='z'; ch++){
        if(mp[ch]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
int main(){
    ll t;
    cin>>t;
    fr(i,1,t+1){
        solve();
    }
    return 0;    
}