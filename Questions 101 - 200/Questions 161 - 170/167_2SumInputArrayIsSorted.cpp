#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    
    int left, right;
    left = 0;
    right = numbers.size()-1;
    
    int sum = numbers[left] + numbers[right];
    
    while(sum != target && left<right) {
        if(sum < target){
            left += 1;
        }
        else {
            right -= 1;
        }
        sum = numbers[left] + numbers[right];
    }
    
    if (left == right)
        return {};

    vector<int> res;
    return {left+1, right+1};
}

int main() {

    vector<int> arr;
    int n, ele, target;

    cout<<"Enter array size: ";
    cin>>n;

    for(int i=0; i<n; i++) {
        cout<<"Enter element "<<i+1<<" : ";
        cin>>ele;
        arr.push_back(ele);
    }

    cout<<"Enter target element: ";
    cin>>target;

    vector<int> res = twoSum(arr, target);

    if(res.size())
        cout<<"Found 2 sum at index: "<<res[0]<<" and "<<res[1];
    else
        cout<<"No 2 sum found";
    
    return 0;
}