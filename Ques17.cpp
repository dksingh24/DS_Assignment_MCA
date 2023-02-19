/*
17. Given array[] with sliding window of size w which is moving from the very left of the
    array to very right. Assume that we can only see the w numbers in the window. Each
    time the sliding window moves right forwards by on position. For example: The array
    is [1 3 -1 -3 5 3 6 7], and w is 3.

                Window position                Max
                [1 3 -1] -3  5  3  6  7         3
                1 [3  -1 -3] 5  3  6  7         3
                1  3 [-1 -3 5]  3  6  7         5
                1  3  -1 -3 [5  3 6]  7         5
                1  3  -1 -3  5 [3  6  7]        6
                1  3  -1 -3  5  3  6  7         7
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> v;
        int max_value=0;
        vector<int> sub_v(nums.begin() , nums.begin() + (k));
        for(int i=k ; i<nums.size() ; i++){
            v.push_back(*max_element(sub_v.begin(),sub_v.end()));
            sub_v.erase(sub_v.begin());
            sub_v.push_back(nums[i]);
        }
        v.push_back(*max_element(sub_v.begin(),sub_v.end()));
        return v;
    }

int main(){
    int n;
    cout<<"Enter the size of array = ";
    cin>>n;
    cout<<"Enter the Array = ";
    vector<int> a;
    int data;
    for(int i=0 ; i<n; i++){
        cin>>data;
        a.push_back(data);
    }
    int w;
    cout<<"Enter the size of Window = ";
    cin>>w;
    vector<int> max;
    max = maxSlidingWindow(a,w);
    for(int x : max)
        cout<<x<<" ";
    return 0;
}