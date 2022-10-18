#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int>& nums, int a, int b){
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
    return;
}

void moveZeroes(vector<int>& nums) {
    
    int lastNonZero = 0;
    for(int searchingForZero = 0; searchingForZero < nums.size(); searchingForZero++){
        if(nums[searchingForZero] != 0){
            swap(nums, lastNonZero, searchingForZero);
            lastNonZero++;
        }
    }        
}

void printArray(vector<int> &nums) {
    for(int i=0; i<nums.size(); i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main() {

    int n, t;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums;

    while(n){
        cout<<"Enter array element: ";
        cin>>t;
        nums.push_back(t);
        --n;
    }

    cout<<"Before moving zeros: ";
    printArray(nums);

    moveZeroes(nums);

    cout<<"After moving zeros: ";
    printArray(nums);

    return 0;
}