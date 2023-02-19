/*
16. Given a stack of integers, how do you check whether each successive pair of members
    in the stack is consecutive or not. The pairs can be increasing or decreasing, and if the
    stack has an odd number of elements, the element at the top is left out of pair. For
    example, if stack of elements are [4, 5, -2, -3, 11, 10, 5, 6, 20], then the output should
    be true because each of the pairs (4,5), (-2,-3), (11,10) and (5,6) consists of
    consecutive numbers.
*/

#include <bits/stdc++.h>
using namespace std;

bool pairWiseConsecutive(stack<int> s)
{
    if(s.size() % 2 != 0){
        s.pop();
    }
    int n1;
    while(!s.empty()){
        n1 = s.top();
        s.pop();
        if(abs(n1 - s.top()) == 1){
            s.pop();
        }
        else{
            return false;
        }
    }
    return true;
    
}

int main()
{
    int t;
    cout<<"Enter the Number of Test Cases = ";
    cin>>t;
    
    while(t--)
    {
        stack<int> s;
        int n, tmp;
        cout<<"Enter the size of Stack = ";
        cin>>n;
        cout<<"Enter Elements of Stack = ";
        while(n--){
            cin>>tmp;
	        s.push(tmp);
	    }
	    if (pairWiseConsecutive(s))
            cout << "Yes" << endl;
	    else 
            cout << "No" << endl;
    }
	return 0;
}