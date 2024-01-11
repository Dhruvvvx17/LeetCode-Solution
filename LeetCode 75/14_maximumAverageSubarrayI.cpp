#include<iostream>
#include<vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    double sum = 0.00000;
    double avg = 0.00000;

    // sum of first k numbers
    for(int i=0; i<k; i++){
        sum += nums[i];
    }
    
    // avg of first k numbers
    avg = sum;

    // sliding window sum k elements
    for(int i=k; i<n; i++){
        sum = sum - nums[i-k] + nums[i];
        avg = max(avg, sum);
    }

    return avg/k;
}

int main() {

    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    cout<<"Maximum window average: "<<findMaxAverage(nums, k)<<endl;
    
    return 0;
}