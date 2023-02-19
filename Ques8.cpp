/*
8. [Josephus circle:] N people decided to elect a leader by arranging themselves in a
    circle and eliminating every mth person around the circle, closing ranks as each drops
    out. Find which person will be the last one remaining (with rank 1).
*/

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *prev;
    node *next;
    node(){
        data = 0;
        prev = NULL;
        next = NULL;
    }
    node(int data){
        this -> data = data; 
        prev = NULL;
        next = NULL;
    }
};

class CDL{
    public:
        node *head;

        CDL(){
            head = NULL;
        }

        void takeinput(int n){
            int i=0;
            while(++i <= n){
                    node *nnode = new node(i);
                    if(head == NULL){
                        head = nnode;
                        head -> next = head;
                        head -> prev = head;
                    }
                    else{
                        nnode -> next = head;
                        nnode -> prev = head -> prev;
                        nnode -> prev -> next = nnode;
                        head -> prev = nnode;
                    }
            }
        }

        void print(node *head){
            if(head == NULL)
                cout<<"CDL is Empty"<<endl;
            else{
                cout<<"Cricular Double LL = ";
                cout<<head -> data <<" <-> ";
                node *temp = head -> next;
                while( temp != head ){
                    cout<<temp -> data<<" <-> ";
                    temp = temp -> next;
                }
                cout<<head -> data;
            }
            cout<<endl;
        }
};

node* create_CDL(int n){
    CDL c;
    c.takeinput(n);
    c.print(c.head);
    return c.head;
}

int find_leader(int n, int k){         
    node *head = create_CDL(n);         // Creating a Circular Doubly Linked List of n intergers from 1 to n. In this line head will store the head of the CDL created.
    node *temp = head;
    int m = k;
    while( temp -> next != temp){
        while(m-- != 1){
            temp = temp -> next;
        }
        temp -> prev ->next = temp -> next;
        temp -> next ->prev = temp -> prev;
        temp = temp -> next;
        m = k;
    }
    return temp->data;
}

int main(){
    int n;
    cout<<"Enter Number of People = ";
    cin>>n;
    int m;
    cout<<"Enter the value of m = ";
    cin>>m;
    cout<<endl<<find_leader(n,m);
    return 0;
}