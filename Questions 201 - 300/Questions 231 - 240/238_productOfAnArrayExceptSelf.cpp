#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size());
    
    res[0] = 1;
    
    // prefix sum
    for(int i=1; i<nums.size(); ++i){
        res[i] = res[i-1] * nums[i-1]; 
    }
    
    // suffix sum
    int prod =  1;
    for(int i=nums.size()-2; i>=0; --i){
        prod = prod * nums[i+1];
        res[i] = res[i] * prod;
    }
    
    return res;
}

int main() {

    int n, t;
    vector<int> nums;
    cout<<"Enter size of array: ";
    cin>>n;

    while(n){
        cout<<"Enter number: ";
        cin>>t;
        nums.push_back(t);
        --n;
    }

    vector<int> res = productExceptSelf(nums);

    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}