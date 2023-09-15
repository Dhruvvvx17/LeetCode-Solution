// given a target an an array of non-negative integers, return the smallest combination of values that sum up to the target value.
// the numbers can be used repeatedly. If no combination possible return NULL

// Time Complexity brute force is O(n^m * m) - (branching factor ^ tree height * copying array elements)
// Time Complexity with memoization O(m*n * m) - (unique recursive calls * copying array per recursive call)

#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<int, vector<int>> cache;

vector<int> bestSum(int target, vector<int> arr){

    // true base case
    if(target == 0) return {};

    // false base case
    if(target < 0) return {-1};

    // cache lookup
    if(cache.find(target) != cache.end()) return cache[target];

    vector<int> bestRes = {};

    // iterate over all branches
    for(int num: arr){
        vector<int> currRes = bestSum(target-num, arr);

        // check if currRes leads to a solution
        if(currRes.empty() || currRes[0] != -1){
            currRes.push_back(num);

            // check if currRes leads to the best solution
            if(bestRes.empty() || bestRes.size() > currRes.size()){
                bestRes = currRes;
            }
        }
    }

    // if bestRes is still empty, none of the branches led to a solution
    // so mark current target as -1
    if(bestRes.empty())
        bestRes.push_back(-1);

    // store result in cache
    cache[target] = bestRes;
    return cache[target];
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

    vector<int> bestRes = bestSum(target, arr);

    // cout<<"Printing cache: "<<endl;
    // for(auto x: cache){
    //     int key = x.first;
    //     vector<int> value = x.second;

    //     cout<<"Key: "<<key<<" Value: ";
    //     for(int v: value){
    //         cout<<v<<" ";
    //     }
    //     cout<<endl;
    // }

    if(bestRes.empty())
        cout<<target<<" cannot be generated from array"<<endl;
    else {
        cout<<target<<" can be generated from array elements: ";
        for(int num : bestRes){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
}