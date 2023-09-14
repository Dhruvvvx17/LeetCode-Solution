// given a target an an array of non-negative integers, find out if the target can be constructed using the number of the array.
// the numbers can be used repeatedly.
// Time Complexity with memoization O(m*n) - m is the target and n is the number of elements.
#include<iostream>
#include<map>
#include<vector>
using namespace std;

map<int, bool> cache;

bool canSum(int target, vector<int> arr) {
    if(target < 0) return false;
    if(target == 0) return true;
    if(cache.find(target) != cache.end()) return cache[target];

    for(int num: arr){
        if(canSum(target-num, arr)){
            cache[target] = true;
            return true;            
        }
    }
    cache[target] = false;
    return false;
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

    if(canSum(target, arr))
        cout<<target<<" can be generated from array"<<endl;
    else
        cout<<target<<" cannot be generated from array"<<endl;

    return 0;
}