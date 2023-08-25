#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    if (nums.size() == 1)
        return nums[0];
    
    // left and right pointers
    int left = 0;
    int right = nums.size()-1;
    
    // if last element greater than first then simply return first
    if(nums[right]>nums[left])
        return nums[left];
    
    // else find the inflection point
    while(right >=left) {
        int mid = left + (right-left)/2;
        
        if(nums[mid]>nums[mid+1])
            return nums[mid+1];
        
        if(nums[mid-1]>nums[mid])
            return nums[mid];
        
        // modify index
        if(nums[mid]>nums[0])
            left = mid + 1;
        else
            right = mid-1;
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    vector<int> arr;

    cout<<"Enter the array elements: ";
    int ele;
    for(int i=0; i<n; i++){
        cin>>ele;
        arr.push_back(ele);
    }

    // rotate array here

    int index = findMin(arr);

    cout<<"Min at index "<<index;
    return 0;
}