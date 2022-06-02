// fix needed - using long for answer, need to use int

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int bitSum, bitRem, pos=0, currLSB;
    long res=0;
    
    // iterate bitwise over 32 bits
    for(int i=0; i<32; i++){
        bitSum = 0;
        
        // iterate over all nums
        for(int j=0; j<nums.size(); j++){
            
            // extract LSB
            currLSB = nums[j]&1;
            
            // add LSB to bitSum
            bitSum += currLSB;
            
            // shift num right to modify LSB as required by next iteration
            nums[j] = nums[j]>>1;
        }
        
        // get bitRem as bitSum%3 (all numbers in nums repeat thrice except one)
        // bit rem wil be the bit (0/1) that could not form a triplet
        bitRem = bitSum%3;
        
        res = res + pow(2,pos)*bitRem;
        
        // increment position (goint from LSB to MSB)
        pos++;
    }
    return res;
}

int main() {
    int n;
    cout<<"Enter number of numbers: ";
    cin>>n;

    vector<int> nums(n);

    for(int i=0; i<n; i++) {
        cout<<"Enter number "<<i+1<<" : ";
        cin>>nums[i];
    }

    cout<<"Single Number is: "<<singleNumber(nums);

    return 0;
}