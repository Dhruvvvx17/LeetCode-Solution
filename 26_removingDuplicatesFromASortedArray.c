#include<stdio.h>
#include<stdlib.h>

int removeDuplicates(int* nums, int numsSize){

    if(numsSize==0 || numsSize==1)
        return numsSize;    
    
    int new_index = 0;
    
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=nums[new_index]){
            new_index += 1;
            nums[new_index] = nums[i];
        }
    }
    
    return new_index+1;
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int *arr = (int*)malloc(sizeof(int)*n);
    printf("Enter the array elements [SORTED]: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Original array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    int new_n = removeDuplicates(arr,n);

    printf("Array after removing duplicates: ");
    for(int i=0;i<new_n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
