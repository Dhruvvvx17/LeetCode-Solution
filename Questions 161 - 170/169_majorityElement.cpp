#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    // moore's voting algorithm
    int count = 0, majority;
    
    for(int x: nums) {
        if(!count){
            majority = x;
        }
        count += (majority == x) ? +1 : -1;
    }
    
    return majority;
}

int main() {
    vector<int> arr;
    int n, ele;

    cout<<"Enter array size: ";
    cin>>n;

    for(int i=0; i<n; i++) {
        cout<<"Enter element "<<i+1<<" : ";
        cin>>ele;
        arr.push_back(ele);
    }

    cout<<"Majority Element: "<<majorityElement(arr);
    
}