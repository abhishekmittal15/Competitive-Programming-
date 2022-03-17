#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
using namespace std;
#define int long long int 

signed main(){

	double k,p,x;
	cin>>k>>p>>x;
	double M=floor(sqrt(k*p/x));
	/* cout<<M<<endl; */
	double answer=min(M*x+k*p/M,(M+1)*x+k*p/(M+1));
	/* cout<<setprecision(20)<<answer<<endl; */
	printf("%0.3lf\n",answer);
	return 0;

}
