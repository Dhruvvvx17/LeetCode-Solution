// Combine the arrays then find the median based on odd or even number of elements

#include<stdio.h>
#include<stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int *res = (int*)malloc(sizeof(int)*(nums1Size+nums2Size));
    int i=0,j=0,k=0;
    while(i<nums1Size && j<nums2Size){
        if(nums1[i]<nums2[j]){
            res[k] = nums1[i];
            i+=1;
            k+=1;
        }
        else{
            res[k] = nums2[j];
            j+=1;
            k+=1;
        }
    }
    while(i<nums1Size){
        res[k] = nums1[i];
        i+=1;
        k+=1;
    }
    while(j<nums2Size){
        res[k] = nums2[j];
        j+=1;
        k+=1;
    }
    
    int total_len = nums1Size + nums2Size;
    if(total_len%2==1)
        return(res[total_len/2]);
    else
        return((double)(res[total_len/2] + res[total_len/2 - 1])/2.0);
}


void main(){
    int *a1 = (int*)malloc(sizeof(int)*2);
    a1[0] = 1;
    a1[1] = 2;

    int *a2 = (int*)malloc(sizeof(int)*2);
    a2[0] = 3;
    a2[1] = 4;

    printf("Median of the two arrays = %lf",findMedianSortedArrays(a1,2,a2,2));
    return;
}