/*
10. Suppose there are two singly linked lists both of which intersect at some point and
    become a singly list. The head or starting pointers for the both lists are known, but the
    intersecting node is not known. Also the number of nodes in each of the lists before
    they intersect is unknown and may be different in each list. List1 may have n nodes
    before it reaches the intersection point, and list2 might have m nodes before it reaches
    the intersection point where m and n may be m=n, m<n or m>n. write a program for
    find a merging node.
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

node *getIntersectionNode(node *headA, node *headB) {
    if(headA == NULL || headB == NULL)
        return NULL;

    node *tA = headA, *tB = headB;
    while(tA != tB){
        tA = tA == NULL ? headB : tA -> next;
        tB = tB == NULL ? headA : tB -> next;
    }
    return tA;
}

int main(){
    node *headA = new node;
    headA = takeinput();
    node *headB = new node;
    headB = takeinput();
    int intersected_value;
    cout<<"Enter the intersected value = ";
    cin>>intersected_value;
    node *res = new node;
    if(intersected_value == 0)
        res = getIntersectionNode(headA, headB);
    else{
        int skipA, skipB;
        cout<<"Enter the number of nodes before intersection of LIST 1 = ";
        cin>>skipA;
        cout<<"Enter the number of nodes before intersection of LIST 2 = ";
        cin>>skipB;
        
        
        node *tempA = headA, *tempB = headB;
        while(skipA-- > 1)
            tempA = tempA -> next;
        while(skipB-- >= 1)
            tempB = tempB -> next;
        
        //intersection code
        tempA -> next = tempB;
        res = getIntersectionNode(headA, headB);
    }
    
    if(res == NULL)
        cout<<"No Intersection";
    else if(res -> data == intersected_value)
        cout<<"Intersected at "<< res -> data;
    return 0;
}