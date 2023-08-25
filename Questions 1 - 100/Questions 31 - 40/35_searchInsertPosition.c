#include<stdio.h>
#include<stdlib.h>

int searchInsert(int* nums, int numsSize, int target){

    if(target==nums[0])
        return 0;
    
    if(target==nums[numsSize-1])
        return numsSize-1;
    
    int l,r,m;
    l = 0;
    r = numsSize-1;
    
    while(l<=r){
        if((r+l)%2==0)
            m = (r+l)/2;
        else
            m = (r+l-1)/2;
        
        if(nums[m]==target)
            return m;
        else if(target>nums[m])
            l = m+1;
        else
            r = m-1;
    }
    return l;
}

int main(int argc, char const *argv[])
{
    int *arr = (int*)malloc(sizeof(int)*10);
    printf("Enter array elements [SORTED]: ");
    for(int i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter key: ");
    scanf("%d",&key);

    printf("Position of target %d (or where it should be inserted is) is = %d\n",key,searchInsert(arr,10,key));
    return 0;
}
