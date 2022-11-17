#include<iostream>
#include<vector>
#include<map>

using namespace std;

int DFS(vector<int> &nums, int index, int target, int total, map<pair<int, int>, int> &dp){
    
    if(index == nums.size()) {
        return (total == target) ? 1 : 0;
    } 
    
    if(dp.find({index, total}) != dp.end()){
        return dp[{index, total}];
    }
    
    else {
        dp[{index, total}] = DFS(nums, index + 1, target, total + nums[index], dp) 
                            + DFS(nums, index + 1, target, total - nums[index], dp);
    }
    
    return dp[{index, total}];
}


int findTargetSumWays(vector<int>& nums, int target) {
    map<pair<int,int>, int> dp;

    int index = 0;
    int total = 0;
    
    int res = DFS(nums, index, target, total, dp);
    
    return res;
}
    
int main() {

    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    
    cout<<"Number of ways to obtain target: "<<findTargetSumWays(nums, target);

    return 0;
}