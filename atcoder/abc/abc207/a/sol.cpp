#include<cstdio>
#define int long long int 
signed main(){
    int a,b,c;
    scanf("%lld", &a);
    scanf("%lld", &b);
    scanf("%lld", &c);
    int min=(a<b)?a:b;
    min = (min < c) ? min : c;
    printf("%lld\n",a+b+c-min);
    return 0;
}