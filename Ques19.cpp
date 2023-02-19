/*
19. Given an integer k and a queue of integers, how do you reverse the order of first k
    elements of the queue, leaving the other elements in the same relative order? For
    example, if k=4 and queue have the elements [10, 20, 30, 40, 50, 60, 70, 80, 90]; the
    output should be [40, 30, 20, 10, 50, 60, 70, 80, 90].
*/

#include <bits/stdc++.h>
using namespace std;

// Function to reverse first k elements of a queue.
void modifyQueue(queue<int> &q, int k) {
    stack<int> s;
    int i = k;
    while(i--){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    i = q.size() - k;
    int n;
    while(i--){
        n = q.front();
        q.pop();
        q.push(n);
    }
}

void Print(queue<int> Queue)
{
    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
    cout<<endl;
}

int main() {
    int t;
    cout<<"Enter the Number of Testcases = ";
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cout<<"Enter the size of Queue = ";
        cin >> n;
        cout<<"Enter the Value of K = ";
        cin>>k;
        queue<int> q;
        cout<<"Enter the Queue Elements = ";
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        cout<<"Original Queue = ";
        Print(q);
        modifyQueue(q, k);
        cout<<"Reversed Queue = ";
        Print(q);
        cout << endl;
    }
}