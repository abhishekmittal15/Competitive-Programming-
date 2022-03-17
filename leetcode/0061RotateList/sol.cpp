#include<iostream>
using namespace std;

struct ListNode{

	int val;
	ListNode* next;
	ListNode(): val(0),next(nullptr) {}
	ListNode(int x): val(x),next(nullptr) {}
	ListNode(int x,ListNode* next): val(x),next(next) {}

};

void print(ListNode* head){

	ListNode* current=head;
	while(current!=nullptr){
		cout<<current->val<<endl;
		current=current->next;
	}

}

ListNode* solve(ListNode* head,int k){

	ListNode* current=head;
	int n=0;
	while(current!=nullptr){
		n++;
		current=current->next;
	}
	/* cout<<"n :"<<n<<endl; */
	k=k%n;
	if(k==0)
		return head;
	int new_tail_index=n-k;
	ListNode* new_head;
	int idx=1;
	current=head;
	while(idx<new_tail_index){
		idx++;
		current=current->next;
	}
	new_head=current->next;
	current->next=nullptr;
	current=new_head;
	while(current->next!=nullptr)
		current=current->next;
	current->next=head;
	return new_head;

}

int main(){

	int n,k;
	cin>>n>>k;
	ListNode* head=new ListNode(0);
	ListNode* dum=head;
	for(int i=0;i<n;i++){
		int val;
		cin>>val;
		dum->next=new ListNode(val);
		dum=dum->next;
	}
	head=head->next;
	print(head);
	ListNode* ans=solve(head,k);
	print(ans);
	return 0;

}
