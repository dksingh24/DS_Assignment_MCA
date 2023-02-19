/*
6. Given an array of n numbers, create an algorithm which displays all pairs whose sum
    is S.
*/

#include<iostream>
using namespace std;

void find_pairs(int a[],int n, int s){
    int f=0;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(a[i] + a[j] == s){
                cout<<a[i]<<","<<a[j]<<"\n";
                a[j]=0;
                f=1;
            }
    if(f==0)
        cout<<"No such pair is present";
}

int main(){
    int n,s;
    cout<<"Enter the size of array = ";
    cin>>n;
    int *a=new int[n];
    cout<<"Enter the array ";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the sum whose pairs are found = ";
    cin>>s;
    find_pairs(a,n,s);
    return 0;
}