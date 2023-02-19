/*
11. Check whether the given linked list is either NULL-terminated or ends in cycle
    (cyclic).
*/

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(){
        data = 0;
        next = NULL;
    }
    node(int data){
        this -> data = data;
        next = NULL;
    }
};

node *takeinput(){
    int data;
    cout<<"Enter the data (Enter -1 to end the List) = ";
    cin>>data;
    node *head=NULL;
    node *tail = NULL;
    while(data != -1){
        node *nnode = new node(data);
        if(head == NULL){
            head = nnode;
            tail = nnode;
        }
        else{
            tail -> next = nnode;       
            tail = nnode;               
        }
        cout<<"Enter the data (Enter -1 to end the List) = ";
        cin >> data;
    };
    return head;
}

bool check_for_cyclic(node *head){
    node *slow= head, *fast= head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast)
            return true;
    }
    
    return false;
}



int main(){
    node *head = new node;
    head = takeinput();
    if(check_for_cyclic(head))
        cout<<"The List is cyclic.";
    else
        cout<<"The List is NULL-terminated.";
    return 0;
}