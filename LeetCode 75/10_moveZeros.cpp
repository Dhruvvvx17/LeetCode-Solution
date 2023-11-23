#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int non_zero = 0;
    int zero = 0, temp;

    while(non_zero < nums.size()) {
        if(nums[non_zero] != 0){
            temp = nums[non_zero];
            nums[non_zero] = nums[zero];
            nums[zero] = temp;
            zero++;
        }
        non_zero++;
    }
}

int main() {
    vector<int> nums = {0,1,0,3,12};

    moveZeroes(nums);

    for(int x: nums){
        cout<<x<<" ";
    }
    cout<<endl;
}