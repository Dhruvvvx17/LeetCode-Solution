#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int left, int right, int target) {
    
    // invalid return -1
    if(left>right)
        return -1;

    int mid = (right + left)/2;
    // element found
    if(nums[mid] == target)
        return mid;
    
    // search right
    if(nums[mid] < target)
        return binarySearch(nums, mid+1, right, target);
    
    // search left
    return binarySearch(nums, left, mid-1, target);
}


int search(vector<int>& nums, int target) {
    return binarySearch(nums, 0, nums.size()-1, target);    
}

int main() {

    int n, t;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums;
    while(n) {
        cout<<"Enter element: ";
        cin>>t;
        nums.push_back(t);
        --n;
    }
    cout<<endl;

    int target;
    cout<<"Enter target: ";
    cin>>target;

    int pos = search(nums, target);
    if( pos == -1)
        cout<<target<<" not found in array";
    else
        cout<<target<<" found at index "<<pos;
    
    return 0;
}