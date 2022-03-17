#include<iostream>
#include<vector>
using namespace std;
#define int long long int 

int max_sz=5;
signed main(){

	int a,b,ans=0;
	cin>>a>>b;
	for(int i=1;i<=max_sz;i++){
		int start=min(max(i*i,a),b);
		int end=b;
		int multiple_start=(start/i+(start%i==0?0:1))*i;
		if(multiple_start>b)
			continue;
		int num_multiples=(end-multiple_start+1)/i;
		cout<<i<<" "<<multiple_start<<" "<<num_multiples<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

/* 1 2 3 4 5 */ 

/*  6  7  8  9  10 11 12 13 14 */  
 
/*  1  1  1  1  1  1  1  1  1 */
/*  6  7  8  9  10 11 12 13 14 */

/*  2     2     2     2     2 */
/*  3     4     5     6     7 */

/*  3        3        3 */      
/*  2        3        4 */

/*        4           4 */ 
/* 	   2           3 */

/*              5 */     
/* 			 2 */
