#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long int 

struct node{
    node* next;
    node* prev;
    int data=0;
};


signed main(){

    struct node *head=new node;
    head->data=0;
    head->next=nullptr;
    head->prev=nullptr;
    struct node *root=new node;
    root=head;
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){

        struct node *current=new node;
        current->data=i;
        if(s[i-1]=='L'){
            current->prev=head->prev;
            current->next=head;
            if(head->prev!=nullptr)
                head->prev->next=current;
            head->prev=current;
        }
        else{
            current->next=head->next;
            current->prev=head;
            if(head->next!=nullptr)
                head->next->prev=current;
            head->next=current;
        }
        head=current;
    }
    while(head->prev!=nullptr){
        head=head->prev;
    }
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}