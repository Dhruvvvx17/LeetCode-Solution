// DID NOT UNDERSTAND

#include<stdlib.h>
#include<stdio.h>

int canJump(int* nums, int numsSize){
    int max_index = nums[0];
    if (numsSize < 2) // if only one element - always true
        return 1;
    
    if (max_index == 0) // can't jump at all
        return 0;
    
    if (max_index >= numsSize) // first jump can reach end
        return 1;
    
    for (int i=1; (i <= max_index) && (i < numsSize); ++i) //loop through all reachable indexes
    {
        if (i + nums[i] > max_index)
            max_index = i + nums[i];
    }
    
    if (max_index >= numsSize-1) // if maximum jump is more than last index, can reach end
        return 1;
    return 0;
}