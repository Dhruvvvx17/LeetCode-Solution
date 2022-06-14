#include<iostream>
#include<vector>
using namespace std;

// method declarations
int findKthLargest(vector<int>&, int);
int quickSelect(vector<int>&, int, int, int);

// method definitions
int findKthLargest(vector<int>& nums, int k) {
    // 1st Method -> Sort and fetch. Complexity -> O( nlogn )
    // Time taken -> 11ms
    // sort(nums.begin(), nums.end());
    // return nums[nums.size()-k];
    
    
    // 2nd Method -> Quick Select. Complexity -> avg: O(n) worst case: O(n^2)
    // Time taken -> 290ms

    // in case of kth smallest element, in a sorted array the answer would be at nums[k]
    // in case of kth largest element, in a sorted array the answer would be at nums[nums.size() - k]

    // modify k, now need to simply fetch nums[k]
    k = nums.size() - k;        
    return quickSelect(nums, k, 0, nums.size()-1);
}

// inspired by quick sort partitioning
// we reduce our search space by grouping the elements lower and higher than a pivot element to either side of the array.
// the pivot itself is sorted by the end of the partitioning
int quickSelect(vector<int>& nums, int k, int left, int right) {
    int pivot = nums[right];
    int p = left;
    int temp;
    
    for(int i=left; i<right; i++) {
        
        // if current num less than pivot, swap with position at p
        if(nums[i] <= pivot) {
            temp = nums[p];
            nums[p] = nums[i];
            nums[i] = temp;
            
            // increment p
            ++p;
        }
    }
    
    // all elements to the left of p are smaller than or equal to pivot
    // finally swap pivot to position p, which is its sorted position
    temp = nums[p];
    nums[p] = pivot;
    nums[right] = temp;
    
    // search space -> left of p
    if(k<p) return quickSelect(nums, k, left, p-1);
    
    // search space -> right of p
    if(k>p) return quickSelect(nums, k, p+1, right);
        
    // if k == p -> return current element as that is in its sorted position
    return nums[p];
}

int main() {

    int n, temp, k;
    vector<int> nums;

    cout<<"Enter number of numbers: ";
    cin>>n;

    while(n) {
        cout<<"Enter number: ";
        cin>>temp;
        nums.push_back(temp);
        --n;
    }

    cout<<"Enter k value: ";
    cin>>k;

    cout<<k<<"th largest number in the array is: "<<findKthLargest(nums, k);

    return 0;
}