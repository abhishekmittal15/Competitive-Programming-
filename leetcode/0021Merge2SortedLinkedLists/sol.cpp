#include<iostream>
using namespace std;

#define int long long int 

struct ListNode{
	int val;
	ListNode* next;
	ListNode() : val(0),next(nullptr) {}
	ListNode(int val) : val(val),next(nullptr) {}
	ListNode(int val,ListNode* next) : val(val), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){

	ListNode* current=new ListNode();
	ListNode* answer=current;
	while(l1!=nullptr and l2!=nullptr){
	
		if(l1->val<l2->val){
			current->next=l1;
			l1=l1->next;
		}
		else{
			current->next=l2;
			l2=l2->next;
		}
		current=current->next;
	}
	while(l1!=nullptr){
		current->next=l1;
		l1=l1->next;
		current=current->next;
	}
	while(l2!=nullptr){
		current->next=l2;
		l2=l2->next;
		current=current->next;
	}
	return answer->next;

}

void print(ListNode* head){
	
	ListNode* ptr=head;
	while(ptr!=nullptr){
		cout<<ptr->val<<endl;
		ptr=ptr->next;
	}

}

signed main(){

	int n1,n2;
	cin>>n1>>n2;
	ListNode* head1=new ListNode(0);
	ListNode* head2=new ListNode(0);
	ListNode* current=head1;
	for(int i=0,a;i<n1;i++){
		cin>>current->val;
		if(i==n1-1)
			continue;
		ListNode* new_node=new ListNode();
		current->next=new_node;
		current=new_node;
	}
	current=head2;
	for(int i=0,a;i<n2;i++){
		cin>>current->val;
		if(i==n2-1)
			continue;
		ListNode* new_node=new ListNode();
		current->next=new_node;
		current=new_node;
	}
	/* print(head2); */
	ListNode* answer=mergeTwoLists(head1, head2);
	print(answer);
	return 0;

}
