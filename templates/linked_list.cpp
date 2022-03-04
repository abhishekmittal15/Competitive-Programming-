#include<iostream>
using namespace std;

template<class T>
struct node{
    T data;
    struct node<T>* prev;
    struct node<T>* next;
    node(T val){
        data=val;
        prev=nullptr;
        next=nullptr;
    }
};

template<class T>
class linked_list{
    private:
    struct node<T>* head;
    struct node<T>* tail;
    int num_nodes=0;
    public:
    linked_list(T data);
    void add_first(T data);
    void add_last(T data);
    void del_first();
    void del_last();
    void print();
};

template<class T>
linked_list<T>::linked_list(T data){
    head=new node<T>(data);
    tail=head;
    num_nodes=1;
}

template<class T>
void linked_list<T>::add_first(T data){
    struct node<T>* new_node=new node<T>(data);
    head->prev=new_node;
    new_node->next=head;
    head=new_node;
    num_nodes++;
}

template<class T>
void linked_list<T>::add_last(T data){
    struct node<T>* new_node=new node<T>(data);
    tail->next=new_node;
    new_node->prev=tail;
    tail=new_node;
    num_nodes++;
}

template<class T>
void linked_list<T>::del_last(){
    tail=tail->prev;
    delete tail->next;
    tail->next=nullptr;
    num_nodes--;
}

template<class T>
void linked_list<T>::del_first(){
    head=head->next;
    delete head->prev;
    head->prev=nullptr;
    num_nodes--;
}

template<class T>
void linked_list<T>::print(){
    struct node<T>* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    int x=5;
    linked_list<int> ll(5);
    ll.add_first(6);
    ll.add_last(8);
    ll.print();
    return 0;
}