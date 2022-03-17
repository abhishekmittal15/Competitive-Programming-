#include<iostream>
#include<vector>
using namespace std;

vector<double> solve(vector<int>& cnts){

	int n=cnts.size();
	vector<double> answer(5);
	answer[0]=n+1;
	answer[1]=-1;
	int sum=0;
	int non_zero_freqs=0;
	int max_freq=0;
	for(int i=0;i<n;i++){
		if(cnts[i]>0){
			answer[0]=min(answer[0],(double)(i));
			answer[1]=max(answer[1],(double)(i));
			non_zero_freqs+=cnts[i];
		}
		sum+=(i*cnts[i]);
		if(max_freq<cnts[i]){
			max_freq=cnts[i];
			answer[4]=i;
		}
	}
	answer[2]=(double)(sum)/(double)(non_zero_freqs);
	int med_left=n/2,med_right=n/2+1;
	if(n%2==1)
		med_left=n/2+1;
	int running_cnt=0;
	for(int i=0;i<n;i++){
		if(running_cnt<med_right and running_cnt+cnts[i]>=med_right)
			answer[3]+=i;
		if(running_cnt<med_left and running_cnt+cnts[i]>=med_left)
			answer[3]+=i;
		running_cnt+=cnts[i];
	}
	answer[3]=answer[3]/2;
	return answer;
}

int main(){

	int n=256;
	cin>>n;
	vector<int> cnts(n);
    for(int i=0;i<n;i++){
		cin>>cnts[i];
	}
	vector<double> answer=solve(cnts);
	cout<<"Minimum : "<<answer[0]<<endl;
	cout<<"Maximum : "<<answer[1]<<endl;
	cout<<"Mean : "<<answer[2]<<endl;
	cout<<"Median : "<<answer[3]<<endl;
	cout<<"Mode : "<<answer[4]<<endl;
	return 0;

}
