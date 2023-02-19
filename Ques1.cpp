/*
1. Given an array of elements, replace every element with nearest greater element on the
right of that element.
*/

#include<iostream>
#include<limits.h>
using namespace std;

void replace(int a[], int n){
    int d,i,j;
    for(i=0;i<n-1;i++){
        d=INT_MAX;
        for(j=i+1;j<n;j++){
            if((d > (a[j] - a[i])) && ((a[j] - a[i]) > 0)){
                d=a[j] - a[i];
            }
        }
        if(d!=INT_MAX){
        a[i]=a[i]+d;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the Size of array = ";
    cin>>n;
    int *a=new int[n];
    cout<<"Enter the array = ";
    for(int i=0;i<n;i++)
        cin>>a[i];
    replace(a,n);
    cout<<"\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}