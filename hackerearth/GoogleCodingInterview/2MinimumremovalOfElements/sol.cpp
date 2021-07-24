#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int max_n = 1LL * 1000 * 100 + 5;
int max_sqrt_n = 1LL * 1000;
vector<bool> sieve(max_sqrt_n,true);
vector<int> primes;
void s(){
    for (int i = 2; i * i <= max_sqrt_n;i++){
        if(sieve[i]){
            for (int j = i * i; j < max_sqrt_n;j+=i)
                sieve[j] = false;
        }
    }
}
signed main(){
    int t;
    cin >> t;
    s();
    for (int i = 2; i <= max_sqrt_n;i++)    
    if(sieve[i])
        primes.push_back(i);
    while (t--)
    {
        int n, most_common_prime_factor=-1,occ=0,ans=0;
        cin >> n;
        vector<int> nums(n);
        vector<int> prime_factors(n+1,0);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            int temp = nums[i];
            for (int i = 0; i < primes.size();i++){
                
                if(temp%primes[i]==0){
                    prime_factors[primes[i]]++;
                    while(temp%primes[i]==0)
                        temp = temp / primes[i];
                }
            }
            if(temp>0)
                prime_factors[temp]++;
        }
        for (int i = 2; i <= n;i++)
            if(prime_factors[i]>occ){
                most_common_prime_factor = i;
                occ = prime_factors[i];
            }
        for (int i = 0; i < n;i++)
            if(nums[i]%most_common_prime_factor)
                ans++;
        bool all_ones = true;
        for (int i = 0; i < n;i++)
            if(nums[i]!=1)
                all_ones = false;
        if(all_ones)
            ans = -1;
        cout << ans << endl;
    }
    return 0;
}