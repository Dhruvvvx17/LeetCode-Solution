// Swapping the element to be removed with the last element of the list, then reducing the list size
// Ordering of the array elements does not matter

#include<stdio.h>
#include<stdlib.h>

int removeElement(int* nums, int numsSize, int val){

    int i = 0;
    int n = numsSize-1;
    while(i<=n){
        if(nums[i]==val){
            nums[i] = nums[n];
            n -= 1;
        }
        else{
            i += 1;        
        }
    }
    
    return n+1;
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int *arr = (int*)malloc(sizeof(int)*n);
    printf("Enter the array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int k;
    printf("Enter the element to be removed: ");
    scanf("%d",&k);

    printf("Original array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    int new_n = removeElement(arr,n,k);

    printf("Array after removing all occurances of %d: ",k);
    for(int i=0;i<new_n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
