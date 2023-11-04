#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int prod = 1;
    vector<int> res;
    for(int x: nums){
        prod*=x;
        res.push_back(prod);
    }

    int temp = 1;
    for(int i=nums.size()-1; i>0; i--){
        res[i] = res[i-1] * temp;
        temp = temp * nums[i];
    }

    res[0] = temp;
    return res;
}


int main() {

    vector<int> nums = {1,2,3,4};

    vector<int> res = productExceptSelf(nums);

    cout<<"Product except self: ";
    for(int x: res) {
        cout<<x<<" ";
    }
    cout<<endl;
    
    
    return 0;
}