#include<iostream>
#include<vector>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int k = 1;

    int left = 0, right = 0, longest = 0, n = nums.size();

    while(right < n){
        if(nums[right] == 0) k--;

        if(k < 0){
            if(nums[left] == 0) k++;
            left++;
        }
        else {
            longest = max(longest, right-left+1); 
        }

        right++;
    }

    // -1 to adjust for a deleted element
    return longest-1;
}

int main() {

    vector<int> nums = {0,1,1,1,0,1,1,0,1};

    cout<<"Max length of consecutive 1s after deleting one zero: "<<longestSubarray(nums);
    
    return 0;
}