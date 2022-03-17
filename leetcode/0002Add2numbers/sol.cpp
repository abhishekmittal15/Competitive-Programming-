#include<iostream>
using namespace std;
#define int long long int 

struct ListNode{
	
	int val;
	ListNode* next;
	ListNode() : val(0),next(nullptr) {}
	ListNode(int x) : val(x),next(nullptr){}
	ListNode(int x,ListNode* next): val(x),next(next) {}

};

void print(ListNode* head){

	ListNode* current=head;
	while(current!=nullptr){
		cout<<current->val<<" ";
		current=current->next;
	}
	cout<<endl;
}

ListNode* solve(ListNode* head1,ListNode* head2){

	ListNode* answer=new ListNode(0);
	ListNode* current=answer;
	int sum=0,carry=0;

	while(head1!=nullptr and head2!=nullptr){

		sum=head1->val+head2->val+carry;
		carry=sum/10;
		sum=sum%10;

		current->next=new ListNode(sum);
		current=current->next;

		head1=head1->next;
		head2=head2->next;

	}

	while(head1!=nullptr){

		sum=head1->val+carry;
		carry=sum/10;
		sum=sum%10;

		current->next=new ListNode(sum);
		current=current->next;
		
		head1=head1->next;
	}

	while(head2!=nullptr){

		sum=head2->val+carry;
		carry=sum/10;
		sum=sum%10;

		current->next=new ListNode(sum);
		current=current->next;
			
		head2=head2->next;

	}

	if(carry==1){
	
		current->next=new ListNode(1);

	}
	
	return answer->next;

}

signed main(){
	
	int n,m;
	cin>>n>>m;
	ListNode* head1=new ListNode(0);
	ListNode* head2=new ListNode(0);
	ListNode* current=head1;
	for(int i=0;i<n;i++){

		current->next=new ListNode();
		current=current->next;
		cin>>current->val;

	}
	head1=head1->next;
	print(head1);
	current=head2;

	for(int i=0;i<m;i++){

		current->next=new ListNode();
		current=current->next;
		cin>>current->val;
	
	}
	head2=head2->next;
	print(head2);
	ListNode* answer=solve(head1,head2);
	
	print(answer);
	return 0;

}
