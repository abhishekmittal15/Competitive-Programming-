#include<iostream>
using namespace std;

#define int long long int 

bool solve(int sx,int sy,int tx,int ty){

	while(tx!=ty && tx!=1 && ty!=1){
		
		if(tx<ty)
			swap(tx,ty);
		tx-=(tx/ty)*ty;
		cout<<tx<<" "<<ty<<endl;
	
	}
	while(sx!=sy && sx!=1 && sy!=1){
		
		if(sx<sy)
			swap(sx,sy);
		sx-=(sx/sy)*sy;
		cout<<sx<<" "<<sy<<endl;

			
	}
	cout<<sx<<" "<<sy<<" "<<tx<<" "<<ty<<endl;
	return ((sx==tx)&&(tx==ty)) || (tx==1 && sx==1 && ty>=sy) || (ty==1 && sy==1 && tx>=sx);

}

signed main(){

	int sx,sy,tx,ty;
	cin>>sx>>sy>>tx>>ty;
	bool answer=solve(sx,sy,tx,ty);
	cout<<answer<<endl;
	return 0;

}
