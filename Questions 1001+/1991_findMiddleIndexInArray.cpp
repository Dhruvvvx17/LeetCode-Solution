#include<iostream>
#include<vector>
using namespace std;

int findMiddleIndex(vector<int>& nums) {
    
    int rightSum = 0, leftSum = 0, res = -1;
    
    for(int n: nums)
        rightSum += n;
    
    for(int i=0; i<nums.size(); i++) {
        if(leftSum == rightSum - leftSum - nums[i]) {
            res = i;
            break;
        }
        leftSum += nums[i];
    }
    
    return res;        
}

int main() {

    vector<int> nums;

    int n, t;
    cout<<"Enter number of elements: ";
    cin>>n;

    while(n--){
        cout<<"Enter element: ";
        cin>>t;
        nums.push_back(t);
    }

    int res = findMiddleIndex(nums);

    cout<<"Pivot index: "<<res;
    
    return 0;
}