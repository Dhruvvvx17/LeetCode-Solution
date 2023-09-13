#include<iostream>
#include<vector>
using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> dp(target+1, 0);

    // base case
    dp[0] = 1;

    for(int i=1; i<=target; i++){
        for(int n: nums){
            if(i-n >= 0)
                dp[i] += dp[i-n];
        }
    }

    return dp[target];
}

int main() {
    vector<int> nums = {1,2,3};
    int target = 4;

    cout<<"Number of ways to get "<<target<<" from nums = "<<combinationSum4(nums, target);
        
    return 0;
}