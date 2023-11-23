#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// repetetive 2-sum
unordered_map<int, int> cache;

int maxOperations(vector<int>& nums, int k) {
    int res = 0;

    for(int num : nums) {
        int target = k - num;
        if(cache[target] > 0) {
            cache[target]--;
            res++;
        }
        else {
            cache[num]++;
        }
    }
    return res;
}

int main() {

    vector<int> nums = {1,2,3,4};
    int k = 5;

    int res = maxOperations(nums, k);

    cout<<"Max number of operations: "<<res;

    return 0;
}