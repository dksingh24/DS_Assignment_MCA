/*
2. Recursively remove all adjacent duplicates: Given a string of characters, recursively
remove adjacent duplicate characters from the string. The output string should not
have any adjacent duplicates.

Input:  careermonk Input:  Mississippi
Output: camonk     Output: M
*/

#include<iostream>
#include<string.h>
using namespace std;

void remove(char a[]){
    if(strlen(a)==1)
        return ;
    remove(a+1);
    if(a[0]==a[1]){
        for(int i=2;i<=strlen(a);i+=2){
            a[i-2]=a[i];
            a[i-1]=a[i+1];
        }
    }
    return ;
}

int main(){
    char a[100];
    cout<<"Enter the String = ";
    cin>>a;
    cout<<"Original String = "<<a;
    remove(a);
    cout<<"\n";
    cout<<"New String = "<<a;
    return 0;
}