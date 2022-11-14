#include<iostream>
#include<vector>
using namespace std;

int getMax(int a, int b) {
    return (a>b) ? a : b;
}

int lengthOfLIS(vector<int>& nums) {
    
    vector<int> dp (nums.size(), 1);
    int res = 1;
    
    for(int i=nums.size()-2; i>=0; --i) {
        for(int j=i+1; j<nums.size(); ++j) {
            if(nums[i] < nums[j]) {
                dp[i] = getMax(dp[i], 1+dp[j]);
                if(dp[i] > res)
                    res = dp[i];
                }
            }
        }
    return res;
}

int main() {

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout<<"Length of longest common subsequence is: "<<lengthOfLIS(nums);    
    
    return 0;
}