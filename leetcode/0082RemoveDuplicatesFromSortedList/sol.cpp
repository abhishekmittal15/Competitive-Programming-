#include<iostream>
using namespace std;

#define int long long int 

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
  	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* solve(ListNode* head){


		return head;

	ListNode* current=head;
	while(current!=nullptr){

		int val=current->val;
		ListNode* curr2=current->next;
		while(curr2!=nullptr and curr2->val==val){
			
			if(curr2->next)
				current->next=curr2->next;
			else
				current->next=nullptr;
			
			curr2=curr2->next;
		}
		current=current->next;

	}
	return head;

}

signed main(){
	
	int n;
	cin>>n;
	ListNode* head=new ListNode();
	ListNode* current=head;
	for(int i=0;i<n;i++){
		
		int val;
		cin>>current->val;
		if(i<=n-2){
			current->next=new ListNode();
			current=current->next;
		}

	}
	current=head;
	/* while(current!=nullptr){ */
	/* 	cout<<current->val<<endl; */
	/* 	current=current->next; */
	/* } */
	head=solve(head);
	current=head;
	while(current!=nullptr){
		cout<<current->val<<endl;
		current=current->next;
	}
	return 0;

}
