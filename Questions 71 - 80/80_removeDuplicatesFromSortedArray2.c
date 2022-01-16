#include<stdio.h>
#include<stdlib.h>

int removeDuplicates(int*, int);

void main(){
    int n;
    printf("Enter Size of array (n): ");
    scanf("%d",&n);
    int *arr = (int*)malloc(sizeof(int)*n);
    printf("Enter array elements in sorted order: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int m = removeDuplicates(arr,n);

    printf("New array elements (with max 2 repetition): ");
    for(int i=0;i<m;i++){
        printf("%d ",arr[i]);
    }
}

int removeDuplicates(int* nums, int numsSize){
    int new_pos = 0;
    for(int i=0; i<numsSize; i++){
        if(new_pos<2 || nums[i] > nums[new_pos-2]){
            nums[new_pos] = nums[i];
            new_pos+=1;
        }
    }
    return new_pos;
}