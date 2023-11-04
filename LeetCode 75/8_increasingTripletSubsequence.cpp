// not too sure about this one
#include<iostream>
#include<vector>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
    int n = nums.size();
    vector<int> gre(n, 0);
    gre[n-1] = nums[n-1];

    for(int i=n-2; i>=0; i--){
        gre[i] = max(nums[i], gre[i+1]);
    }

    int cur = 0;
    for(int i=1; i<n-1; i++){
        if(nums[cur] > nums[i]){cur = i;}
        if(nums[cur] < nums[i] && nums[i] < gre[i+1]) return true;
    }

    return false;
}

int main() {

    vector<int> nums = {1,2,3,4,5};

    bool res = increasingTriplet(nums);

    if(res) cout<<"INCREASING TRIPLET";
    else cout<<"NOT INCREASING TRIPLET";
    
    return 0;
}