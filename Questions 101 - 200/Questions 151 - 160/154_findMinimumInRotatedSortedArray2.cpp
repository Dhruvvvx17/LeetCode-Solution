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
    if(nums[right] > nums[left])
        return nums[left];

    // modify index accordingly     
    while(right >=left) {
        int mid = left + (right-left)/2;
        
        if(nums[mid] > nums[right])
            left = mid + 1;
        
        else if(nums[mid] < nums[right])
            right = mid;

        else
            right--;
    }
    return nums[left];
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