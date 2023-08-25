#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// void rotate(vector<int>& nums, int k) {
//     int steps = k % nums.size();
//     std::rotate(nums.rbegin(), nums.rbegin() + k%nums.size(), nums.rend());
//     return;
// }

// reverse array between l and r
void reverse(vector<int>& nums, int l, int r) {
    
    if(nums.size() == 1)
        return;
    
    while(l<r){
        nums[l] = nums[l] + nums[r];
        nums[r] = nums[l] - nums[r];
        nums[l] = nums[l] - nums[r];
        l += 1;
        r -= 1;
    }
    return;
}

// rotate clockwise by k bits
void rotate(vector<int>& nums, int k) {
    
    if(k==0)
        return;
    k = k % nums.size();
    
    reverse(nums, 0, nums.size()-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, nums.size()-1);
    return;
}


void printVector(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<n; i++) {
        cout<<"Element "<<i+1<<" : ";
        cin>> nums[i];
    }

    int k;
    cout<<"Enter the number of right rotations: ";
    cin>>k;

    cout<<"Original array: ";
    printVector(nums);

    rotate(nums, k);
    
    cout<<"Rotated array: ";
    printVector(nums);

    return 0;
}