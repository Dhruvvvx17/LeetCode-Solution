#include<stdio.h>
#include<stdlib.h>

int maxSubArray(int* nums, int numsSize){

    if(numsSize==0)
        return 0;
    
    int currMax = nums[0];
    for(int i=1;i<numsSize;i++){
        if(nums[i-1]>0)
            nums[i] += nums[i-1];

        if(nums[i]>currMax)
            currMax = nums[i];
    }
    
    return currMax;
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    int *arr = (int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Maximum subarray sum: %d",maxSubArray(arr,n));

    return 0;
}
