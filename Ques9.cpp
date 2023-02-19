/*
9. For a given k value (k>0) reverse blocks of nodes in the list.
    Example: Input: 1,2,3,4,5,6,7,8,9,10
    Output for different k values: For k=2: 2,1,4,3,6,5,8,7,10,9
    For k=3: 3,2,1,6,5,4,9,8,7,10 For k=4: 4,3,2,1,8,7,6,5,9,10.
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

bool length(node *temp, int k){
    while( k and temp){
        temp = temp -> next;
        k--;
    }
    return k==0;
}

node* rev(node *head, int k){
    if(k == 1)
        return head;
    if(!length(head, k))
        return head;
    node *prev = NULL, *curr = head, *next = NULL;
    int t=k;
    while(t > 0){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        t--;
    }
    if(next != NULL){
        node *rest_head = rev(next,k);
        head -> next = rest_head;
    }
    return prev;
}

int main(){
    node *head = new node;
    head = takeinput();
    cout<<"The Linked List is as follows : ";
    print(head);
    cout<<"Enter the value of K = ";
    int k;
    cin>>k;
    head = rev(head,k);
    cout<<endl<<"The Reversed Linked List is as follows : ";
    print(head);
    return 0;
}