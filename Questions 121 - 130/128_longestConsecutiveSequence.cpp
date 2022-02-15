// Time complexity - nlogn as sorting takes log(n) time

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if(nums.size()==0) return 0;
    
    // sort the vector
    sort(nums.begin(),nums.end());

    // current and global result
    int curr_longest = 1, global_longest = 0;
    
    for (int i=1; i<nums.size(); i++){
        if(nums[i] - nums[i-1] == 1) curr_longest++;
        
        else if(nums[i] - nums[i-1] > 1){
            global_longest = (curr_longest > global_longest) ? curr_longest : global_longest;
            curr_longest = 1;
        }
    }

    global_longest = (curr_longest > global_longest) ? curr_longest : global_longest;
    return global_longest;        
}

int main(){
    int n, temp;
    vector<int> nums;

    cout<<"Enter number of elements: ";
    cin>>n;

    while(n){
        cout<<"Enter element: ";
        cin>>temp;
        nums.push_back(temp);
        n--;
    }

    cout<<"Longest consecutive sequence = "<<longestConsecutive(nums);

    return 0;
}