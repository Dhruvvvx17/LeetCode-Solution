#include<stdlib.h>
#include<math.h>
#include<stdio.h>

int* searchRange(int* nums, int numsSize, int target);
int getLeftIndex(int* nums, int numsSize, int target);
int getRightIndex(int* nums, int numsSize, int target);

int* searchRange(int* nums, int numsSize, int target){
    int *res = (int*)malloc(sizeof(int)*2);
    
    res[0] = getLeftIndex(nums,numsSize,target);
    res[1] = getRightIndex(nums,numsSize,target);;
    
    // printf("%d %d",res[0],res[1]);

    return res;
}

int getLeftIndex(int* nums, int numsSize, int target){
    int left, right, mid, index=-1;
    left = 0;
    right = numsSize-1;
    
    while(left<=right){
        mid = left + (right-left)/2;
        
        if(nums[mid]==target){
            index = mid;
            right = mid - 1;
        }
        else if(nums[mid]<target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return index;
}

int getRightIndex(int* nums, int numsSize, int target){
    int left, right, mid, index=-1;
    left = 0;
    right = numsSize-1;
    
    while(left<=right){
        mid = left + (right-left)/2;
        
        if(nums[mid]==target){
            index = mid;
            left = mid + 1;
        }
        else if(nums[mid]<target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return index;
}


int main(int argc, char const *argv[])
{
    int n,k;

    printf("Enter array size: ");
    scanf("%d",&n);

    int *arr = (int*)malloc(sizeof(int)*n);
    printf("Enter array elements [SORTED]: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter k value: ");
    scanf("%d",&k);

    int *res;
    res = searchRange(arr,n,k);

    for(int i=0;i<2;i++){
        printf("%d ",res[i]);
    }
    printf("is the starting and ending index of element %d\n",k);

    free(res);
    free(arr);
    return 0;
}
