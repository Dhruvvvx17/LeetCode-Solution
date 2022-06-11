#include<iostream>
#include<vector>
#include<set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    set<int> mySet;
    
    for(int i=0; i<nums.size(); i++) {
        if(mySet.find(nums[i]) != mySet.end())
            return true;
        mySet.insert(nums[i]);
    }
    return false;
}

int main() {

    int n, temp;
    cout<<"Enter the number of numbers: ";
    cin>>n;

    vector<int> nums;
    for(int i=0; i<n; i++) {
        cout<<"Enter number "<<i<<" : ";
        cin>>temp;
        nums.push_back(temp);
    }

    if(containsDuplicate(nums))
        cout<<"Duplicates exist";
    else
        cout<<"Duplicates don't exist";

    return 0;
}