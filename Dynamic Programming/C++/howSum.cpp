// given a target an an array of non-negative integers, return a combination of values that sum up to the target value.
// the numbers can be used repeatedly. If no combination possible return NULL

// Time Complexity brute force is O(n^m * m) - (branching factor ^ tree height * copying array elements)
// Time Complexity with memoization O(m*n * m) - m is the target and n is the number of elements. (Second m is copying array elements)

#include<iostream>
#include<map>
#include<vector>
using namespace std;

map<int, vector<int>> cache;

bool howSum(int target, vector<int> arr, vector<int>& res) {

    if(target < 0) return false;
    if(target == 0) return true;
    if(cache.find(target) != cache.end()){
        res = cache[target];
        if(res.empty()) return false;
        else return true;
    }

    for(int num: arr){
        if(howSum(target - num, arr, res)){
            res.push_back(num);
            cache[target] = vector<int>(res);
            return true;
        }
    }
    cache[target] = vector<int>();
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

    vector<int> res;
    howSum(target, arr, res);

    if(res.empty())
        cout<<target<<" cannot be generated from array"<<endl;
    else {
        cout<<target<<" can be generated from array elements [";
        for(int num : res){
            cout<<num<<" ";
        }
        cout<<"]"<<endl;
    }

    return 0;
}