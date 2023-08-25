#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// 2-pointer smart approach
int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0;
    int sum = 0;
    int res = INT_MAX;
    
    for(int right=0; right<nums.size(); right++) {
        sum += nums[right];
        
        // found a valid sum ie; greater than or equal to s
        while(sum >= target) {
            res = min(res, right + 1 - left);
            // reduce sum by moving current left's value then move left ahead 
            sum -= nums[left++];                
        }
    }
    return res == INT_MAX ? 0 : res;
}

int main() {

    vector<int> nums;
    int input;

    while(true){
        cout<<"Enter a number (-1) to stop: ";
        cin>>input;
        if(input == -1 ) break;
        nums.push_back(input);
    }

    int target;
    cout<<"Enter target sum: ";
    cin>>target;

    int res = minSubArrayLen(target, nums);
    if(res==0)
        cout<<"Min sub array with given target not found";
    else
        cout<<"Min sub array with given sum greater or equal to target found with length "<<res;

    return 0;
}