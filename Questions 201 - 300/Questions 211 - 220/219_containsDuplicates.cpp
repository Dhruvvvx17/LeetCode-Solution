#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> map;
            
    for(int i=0; i<nums.size(); ++i) {
        
        // if current element is not found yet, add it to the map
        if(map.find(nums[i]) == map.end())
            map[nums[i]] = i;
        
        // if current element is found in the map, 
        else {
            // check for the distance between prev and curr index
            if(i - map[nums[i]] <= k)
                return true;
            // update the latest index of the current element
            else
                map[nums[i]] = i;
        }
    }
    return false;
}

int main() {

    int n, temp, k;
    cout<<"Enter number of numbers: ";
    cin>>n;

    vector<int> arr;
    for(int i=0; i<n; i++) {
        cout<<"Enter number at index "<<i+1<<": ";
        cin>>temp;
        arr.push_back(temp);
    }

    cout<<"Enter k value: ";
    cin>>k;

    if(containsNearbyDuplicate(arr, k))
        cout<<"There exists a duplicate in a distance less than or equal to "<<k;
    else
        cout<<"No duplicates exists in a distance less than or equal to "<<k;

    return 0;
}