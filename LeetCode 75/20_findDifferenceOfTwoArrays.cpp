#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

    vector<vector<int>> res = {{}, {}};

    unordered_set<int> s1(nums1.begin(), nums1.end());
    unordered_set<int> s2(nums2.begin(), nums2.end());

    for(int x: s1){
        if(s2.count(x) == 0)
            res[0].push_back(x);
    }

    for(int x: s2){
        if(s1.count(x) == 0)
            res[1].push_back(x);
    }

    return res;
}

int main() {

    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {2,4,6};
    
    vector<vector<int>> res = findDifference(nums1, nums2);

    for(auto x: res) {
        for(auto y: x) {
            cout<<y<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}