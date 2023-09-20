// given a target an an array of non-negative integers, find out if the target can be constructed using the number of the array.
// the numbers can be used repeatedly.
// m - target and n = arr.size()
// Time = O(nm)
// Space = O(m)

#include<iostream>
#include<vector>
using namespace std;

bool canSum_tab(int target, vector<int> arr) {
    vector<bool> table (target+1, false);

    // it is possible to generate 0 from arr (without picking any element)
    table[0] = true;

    // single pass of the table
    for(int i=0; i<table.size(); i++) {
        if(table[i] == true) {
            // for a given true element, change curr_pos + arr[j] to true as well
            for(int j=0; j<arr.size(); j++) {
                // check for out of bounds
                if(i + arr[j] < table.size()) {
                    table[i + arr[j]] = true;
                }
            }
        }
    }

    return table[target];
}

int main() {
    int n, iter = 1, temp, target;
    cout<<"Enter number of elements in array: ";
    cin>>n;

    vector<int> arr;
    while(iter <= n) {
        cout<<"Enter element "<<iter<<": ";
        cin>>temp;
        arr.push_back(temp);
        ++iter;
    }
    
    cout<<"Enter target: ";
    cin>>target;

    if(canSum_tab(target, arr))
        cout<<target<<" can be generated from array"<<endl;
    else
        cout<<target<<" cannot be generated from array"<<endl;

    return 0;
}