#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int getMax(int a, int b) {
    return (a>b) ? a : b;
}

int maxSumAsYouGo(vector<int> nums, int maxLength) {

    vector<int> dp (nums.size(), INT_MIN);

    // first element sum remains the same
    dp[0] = nums[0];

    // iterate over all values
    for(int i=0; i<nums.size(); ++i) {

        // iterate over all values of maxlength
        for(int j=1; j <= maxLength; ++j) {

            if(i-j < 0)
                break;

            dp[i] = getMax(dp[i], nums[i] + dp[i-j]);
        }
    }

    cout<<"Dp array: ";
    for(int i=0; i<dp.size(); i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    return dp[nums.size()-1];
}


int main() {

    vector<int> nums = {10, -4, 6, -10, -3, -5, -2, 8};
    
    int maxLength = 3;

    int res = maxSumAsYouGo(nums, maxLength);
    cout<<"Max sum: "<<res;

    return 0;
}