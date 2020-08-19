#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

int search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize-1;
    
    while(left<=right){
        int mid = floor((left+right)/2);
        int comparator;

        if( (nums[mid]<nums[0] && target<nums[0]) || (nums[mid]>=nums[0] && target>=nums[0]) )
            comparator = nums[mid];
        else if( target<nums[0] )
            comparator = INT_MIN;
        else
            comparator = INT_MAX;
        
        if(comparator==target)
            return mid;
        else if(comparator<target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return -1;
}

int main(int argc, char const *argv[])
{
    int *arr = (int*)malloc(sizeof(int)*10);
    printf("Enter array elements: ");
    for(int i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }
    int target;
    printf("Enter target: ");
    scanf("%d",&target);
    printf("Position of target %d is = %d\n",target,search(arr,10,target));
    return 0;
}
