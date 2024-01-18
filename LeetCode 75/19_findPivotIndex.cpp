#include<iostream>
#include<vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int n = nums.size();

    // edge case - single element
    if(n==1) return 0;

    int revTotal = 0;

    for(int i=n-1; i>=0; i--){
        revTotal += nums[i];
    }

    int leftSum = 0, rightSum = 0;

    for(int i=0; i<n; i++){
        // edge case - first element
        if(i == 0){
            rightSum = 0;
            rightSum = revTotal - nums[i];
        }
        // edge case - last element
        else if(i == n-1){
            leftSum += nums[i-1];
            rightSum = 0;
        }
        else {
            leftSum += nums[i-1];
            rightSum = (revTotal - nums[i]);
        }

        if(leftSum == rightSum) return i;
        revTotal = revTotal - nums[i];
    }

    return -1;
}

int main() {

    vector<int> nums = {1, 7, 3, 6, 5, 6};

    cout<<"Pivot Index: "<<pivotIndex(nums);
    
    return 0;
}