#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define int long long int 

signed main(){

	vector<int> char_pos,temp;
	string s;
	cin>>s;
	int n=s.length();
	int max_char=-1;
	for(int i=0;i<n;i++){
		max_char=max(max_char,1ll*(s[i]-'a'));
	}
	
	for(int i=0;i<n;i++){
		if(s[i]-'a'==max_char)
			char_pos.push_back(i),temp.push_back(i);
	}
	int len=0;
	while(len<n){
		
		int candidates=0;
		int index=-1;
		int cur_max_char=-1;
		for(int i=0;i<char_pos.size();i++){
			int current_index=char_pos[i];
			if(current_index==-1)
				continue;
			if(current_index+1==n){
				char_pos[i]=-1;
				break;
			}
			cur_max_char=max(1ll*(s[current_index+1]-'a'),cur_max_char);
		}
		for(int i=0;i<char_pos.size();i++){
			int current_index=char_pos[i];
			if(current_index==-1)
				continue;
			int next_index=current_index+1;
			if(s[next_index]-'a'!=cur_max_char)
				char_pos[i]=-1;
			else
				char_pos[i]=next_index,candidates++;
		}
		/* cout<<cur_max_char<<endl; */
		if(candidates==1)
			break;
		len++;	
	}
	/* cout<<"----"<<endl; */
	int pos=-1;
	for(int i=0;i<char_pos.size();i++)
		if(char_pos[i]!=-1)
			pos=temp[i];
	cout<<s.substr(pos,n-pos+1)<<endl;
	return 0;

}
