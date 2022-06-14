#include<iostream>
#include<vector>
using namespace std;

void dfsHelper(int target, int currentSum, int k, int count, int startIndex, vector<int> currentPath, vector<vector<int>>& res){
    
    if(currentSum > target || count > k)
        return;
    
    if(currentSum == target && count == k) {
        res.push_back(currentPath);
        return;
    }

    for(int i=startIndex; i<10; ++i) {

        // increment sum by i, add new number to path
        currentSum += i;
        currentPath.push_back(i);
        dfsHelper(target, currentSum, k, count+1, i+1, currentPath, res);

        // after completing the DFS cycle, decrement sum by i and remove sum from path
        currentSum -= i;
        currentPath.pop_back();
    }        
}

vector<vector<int>> combinationSum3(int k, int target) {
    vector<vector<int>> res;
    int currentSum = 0;
    int count = 0;
    int startIndex = 1;
    vector<int> currentPath;

    // passing the final result by reference, but the currentPath by value
    // as the currentPath's state will differ in different iterations
    dfsHelper(target, currentSum, k, count, startIndex, currentPath, res);
    
    return res;

}

int main() {
    int k, target;

    cout<<"Enter target sum: ";
    cin>>target;

    cout<<"Enter minimum number of numbers to be used: ";
    cin>>k;

    vector<vector<int>> res = combinationSum3(k, target);

    if(res.size() == 0) {
        cout<<"Target cannot be reached";
        return 0;
    }

    cout<<"Target can be reached in following ways: "<<endl;
    for(auto x: res) {
        cout<<"[";
        for (auto y: x) {
            cout<<y<<" ";
        }
        cout<<"]"<<endl;
    }

    return 0;
}