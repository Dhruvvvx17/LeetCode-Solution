#include<iostream>
#include<vector>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {

    int l, r;
    l = 0;
    r = nums.size() - 1;
    vector<int> res(nums.size(), -1);
    
    int l_num, r_num;
    
    int i = nums.size()-1;
    
    while(l<=r){
        
        l_num = nums[l] * nums[l];
        r_num = nums[r] * nums[r];
        
        if(l_num < r_num) {
            res[i] = r_num;
            r -= 1;
        }
        else {
            res[i] = l_num;
            l += 1;
        }
        i -= 1;
    }
    
    return res;
}

int main() {

    int n, t;
    cout<<"Enter size of array n: ";
    cin>>n;

    vector<int> nums;

    while(n) {
        cout<<"Enter array element: ";
        cin>>t;
        nums.push_back(t);
        --n;
    }

    vector<int> res = sortedSquares(nums);

    cout<<"Sorted squares array: ";
    for(int i=0; i<res.size(); i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}