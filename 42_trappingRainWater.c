#include<stdio.h>
#include<stdlib.h>

int trap(int* height, int heightSize){
    int *L = height, *R = L + heightSize - 1, max_water_level = 0, water = 0;
    while(L<R){
        int lower = *L < *R ? *L++ : *R--;
        if(lower>max_water_level) max_water_level = lower;
        water += (max_water_level - lower);
    }
    
    return water;
}

int main(int argc, char const *argv[])
{
    int n, *arr;
    printf("Enter array size: ");
    scanf("%d",&n);
    
    arr = (int*)malloc(sizeof(int)*n);
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Maximum rainwater that can be trapped: %d units",trap(arr,n));

    free(arr);
    return 0;
}
