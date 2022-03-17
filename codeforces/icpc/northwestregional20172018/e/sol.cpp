#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(){

	double n,X,v;
	cin>>n>>X>>v;
	vector<pair<double,pair<double,double>>> s(n);
	for(int i=0;i<n;i++){
		double v,l,r;
		cin>>s[i].second.first>>s[i].second.second>>s[i].first;
	}
	/* double t=0; */
	double coeff=0.0;
	double start=0.0;	

	for(int i=0;i<n;i++){
		double l=s[i].second.first;
		double r=s[i].second.second;
		double v=s[i].first;
		coeff+=(r-l)*v;
	}
	double arg=(-1.0*coeff/(v*X));
	if(arg<-1 or arg>1){
		cout<<"Too hard"<<endl;
		return 0;
	}
	double theta=asin(arg);
	/* cout<<theta<<endl; */
	double t=X/(v*cos(theta));
	if(t>=(2*X/v)){
		cout<<"Too hard"<<endl;
		return 0;
	}
	printf("%0.3lf\n",t);
	/* cout<<setprecision(50)<<X/(v*cos(theta))<<endl; */
	return 0;

}
