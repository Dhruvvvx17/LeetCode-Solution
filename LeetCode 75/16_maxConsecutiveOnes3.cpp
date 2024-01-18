#include<iostream>
#include<vector>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int left = 0, right = 0, longest = 0, n = nums.size();

    while(right < n) {

        if(nums[right] == 0) k--;

        // if no bits left to flip, increment left and k (if left was previously pointing at a 0)
        if(k < 0) {
            if(nums[left] == 0) k++;
            left++;
        }
        else {
            longest = max(longest, right-left+1);
        }

        right++;

    }
    return longest;
}

int main() {

    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};

    int k = 2;

    cout<<"Max length of consecutive 1s after flipping k digits: "<<longestOnes(nums, k);
    
    return 0;
}