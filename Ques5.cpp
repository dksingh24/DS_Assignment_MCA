/*
5. [Find the modular node from the end:] Given a singly linked list, write a function
   to find the first from the end whose n%k==0, where n is the number of elements in the
   list and k is an integer constant. If n=19 and k=3 then we should return 16th node.
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

void print(node *head){
    node *temp=head;
    while(temp!=NULL){                      
        cout<<temp->data<<" - > ";
        temp = temp->next;
    }
    cout<<endl;
}

int find_modular_FEnd(node *temp, int k){
    int c=1;
    int index=0;
    while(temp != NULL ){
        if(c % k == 0)
            index = c;
        c++;
        temp = temp -> next;
    }
    return index;
}

int main(){
    node *head = new node;
    head = takeinput();
    cout<<"The Linked List is as follows : ";
    print(head);
    int k;
    cout<<"Enter the value of K = ";
    cin>>k;
    cout<<find_modular_FEnd(head, k)<<"th node is the modular node from the end.";
    return 0;
}