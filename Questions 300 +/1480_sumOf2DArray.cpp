#include<iostream>
#include<vector>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    vector<int> res;
    
    int curr_sum = 0;
    for (int num : nums) {
        curr_sum += num;
        res.push_back(curr_sum);
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

    vector<int> res = runningSum(nums);

    cout<<"Running sum: ";
    for(int r : res){
        cout<<r<<" ";
    }
    
    return 0;
}